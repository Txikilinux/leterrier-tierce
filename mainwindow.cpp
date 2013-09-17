/**
  * Tierce (le Terrier d'AbulÉdu)
  *
  * @warning aucun traitement d'erreur n'est pour l'instant implémenté
  * @see https://redmine.ryxeo.com/projects/leterrier-fubuki
  * @author 2011 André Connes <andre.connes@wanadoo.fr>
  * @author 2011-2012 Eric Seigne <eric.seigne@ryxeo.com>
  * @author 2012-2013 Philippe Cadaugade <philippe.cadaugade@ryxeo.com>
  * @author 2012-2013 Icham Sirat <icham.sirat@ryxeo.com>
  * @see The GNU Public License (GPL)
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful, but
  * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
  * for more details.
  *
  * You should have received a copy of the GNU General Public License along
  * with this program; if not, write to the Free Software Foundation, Inc.,
  * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "btncase.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Langue
    QString locale = QLocale::system().name();

    //Un 1er qtranslator pour prendre les traductions QT Systeme
    //c'est d'ailleur grace a ca qu'on est en RTL
    qtTranslator.load("qt_" + locale,
            QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    qApp->installTranslator(&qtTranslator);

    //Et un second qtranslator pour les traductions specifiques du
    //logiciel
    myappTranslator.load("tierce_" + locale, "lang");
    qApp->installTranslator(&myappTranslator);

    ui->setupUi(this);
    ui->frmAireDeJeu->setStyleSheet("QFrame#frmAireDeJeu {	\nbackground-image: url(:/data_images/cadreNombres);\nbackground-repeat: repeat-no;\nbackground-position: top right;\n}");

    fontBIG.setPointSize(35);
    fontMEDIUM.setPointSize(20);
    fontMINUS.setPointSize(10);

    // défaut
    m_niveau = 0;
    m_niveauMAX = 3;
    m_nLignes = 3;
    m_nColonnes = 4;
    m_message = QString();
    m_isCanceled = false;
    ui->frmAireDeJeu->raise();
    initGrille();
    ui->frmAireDeJeu->setGeometry(400,20,500,480);

    initValeurs();

#ifdef __ABULEDUTABLETTEV1__MODE__
    /// 15/01/2012 Icham -> mode tablette, pas de tooltips (pas de survol en mode tactile, et puis ça faisait des trucs bizarres parfois)
    /// 15/01/2013 iCHAM -> icones survol = icones normales
    // on cherche tous les enfants, et on leur met une chaine vide en tooltips (= desactivation)
    foreach (QWidget *obj, findChildren<QWidget*>()) {
        obj->setToolTip("");
#endif

    /* Positionnement en dur puisque la hauteur de fenêtre "utile" est fixe */
    ui->frmNiveau->move(ui->frmIcones->x()-ui->frmNiveau->width()+8,ui->frmIcones->y()+19);
    ui->frmNiveau->setVisible(false);

    setWindowFlags(Qt::CustomizeWindowHint);
    connect(ui->frmMenuFeuille, SIGNAL(signalAbeMenuFeuilleChangeLanguage(QString)),this,SLOT(slotChangeLangue(QString)),Qt::UniqueConnection);

    QDesktopWidget *widget = QApplication::desktop();
    int desktop_width = widget->width();
    int desktop_height = widget->height();
    this->move((desktop_width-this->width())/2, (desktop_height-this->height())/2);

    ui->btnNiveauBleu->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGrille() {
    ui->lblGrid->setPixmap(":/data_images/cadreNombres"+QString::number(m_niveau));
    ui->lblGrid->adjustSize();
    int dimCase = (475 / m_nColonnes);   // largeur max des cases
    qDebug()<<"Init grille";
    qDebug()<<dimCase;
    for (int i = 0; i < m_nLignes; i++) {
        for (int j = 0; j < m_nColonnes; j++) {
//            QString n = QString::number(i*m_nColonnes +j);
            int n = i*m_nColonnes +j;
            BtnCase *btnCase = new BtnCase(n, ui->frmAireDeJeu);
            btnCase->setObjectName(QString::number(n)); // On donne un nom : #
            /* Les décalages ci-dessous sont dûs aux bordures "solides" à l'intérieur de la grille. Ces nombres sont en dur (comme d'ailleurs dimCase), pour faire simple puisqu'on ne redimensionne pas !! */
            btnCase->setGeometry(3+(dimCase)*j,20+(dimCase*i),dimCase,dimCase);
            btnCase->setVisible(true);
            m_btnCases.append(btnCase);
            connect(btnCase, SIGNAL(clicked()),this,SLOT(attraperBtnCase())); //on connecte le bouton au slot
        }
    }
}

void MainWindow::initValeurs() {
    m_isCanceled = false;
    int nBtn = m_nLignes * m_nColonnes;
    int encore = nBtn;
    QList<int> listeTirage; // ensemble des valeurs v1 et v2 pour éviter les répétitions dans somme = v1 + v2
    m_listeSommes.clear();
    m_listeCouples.clear();
    m_btnCasesNombres.clear();
    m_btnCasesSommes.clear();
    while (encore > 0) {
        int n1, v1;
        do {
            n1 = rand() % nBtn;
        } while (m_btnCases[n1]->getMValeur() > -1);
        do {
            v1 = 1+rand() %nBtn;
        } while (listeTirage.contains(v1));
        listeTirage << v1;
        m_btnCases[n1]->setMValeur(v1);
        m_btnCases[n1]->setMSauve();
        m_btnCases[n1]->setText(QString::number(v1));
        m_btnCases[n1]->setMSomme(false);
        m_btnCases[n1]->setFont(fontBIG);
        m_btnCases[n1]->setDisabled(false);
        m_btnCases[n1]->setMChoisi(false);
        m_btnCases[n1]->setIconeNormale(":/data_images/fondNormal");
        m_btnCases[n1]->setCouleurFondPressed(QColor(255,255,255,50));
        m_btnCases[n1]->setCouleursTexte(QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255));
//        m_btnCases[n1]->setStyleSheet("border:1px solid blue");
        m_btnCasesNombres << m_btnCases[n1];
        m_listeCouples << v1;
        encore--;
        int n2, v2;
        do {
            n2 = rand() % nBtn;
        } while (m_btnCases[n2]->getMValeur() > -1);
        do {
            v2 = 1+rand() %nBtn;
        } while (listeTirage.contains(v2));
        listeTirage << v2;
        m_btnCases[n2]->setMValeur(v2);
        m_btnCases[n2]->setMSauve();
        m_btnCases[n2]->setText(QString::number(v2));
        m_btnCases[n2]->setMSomme(false);
        m_btnCases[n2]->setFont(fontBIG);
        m_btnCases[n2]->setDisabled(false);
        m_btnCases[n2]->setMChoisi(false);
        m_btnCases[n2]->setIconeNormale(":/data_images/fondNormal");
        m_btnCases[n2]->setCouleurFondPressed(QColor(255,255,255,50));
        m_btnCases[n2]->setCouleursTexte(QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255));
//        m_btnCases[n2]->setStyleSheet("border:1px solid blue");
        m_btnCasesNombres << m_btnCases[n2];
        m_listeCouples << v2;
        encore--;
        int n;
        do {
            n = rand() % nBtn;
        } while (m_btnCases[n]->getMValeur() > -1);
        m_btnCases[n]->setMValeur(v1+v2);
        m_btnCases[n]->setMSauve();
        m_btnCases[n]->setText(QString::number(v1+v2));
        m_btnCases[n]->setMSomme(true);
        m_btnCases[n]->setFont(fontBIG);
        m_btnCases[n]->setDisabled(false);
        m_btnCases[n]->setMChoisi(false);
        m_btnCases[n]->setIconeNormale(":/data_images/fondSomme");
        m_btnCases[n]->setCouleursTexte(QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255));
//        m_btnCases[n]->setStyleSheet("border:1px solid blue");
        m_btnCasesSommes << m_btnCases[n];
        m_listeSommes << v1+v2;
        encore--;
    }
    // sauvegarde des listes "coup de pouce" pour pouvoir aider avec RECOMMENCER
    m_listeSommesSauve = m_listeSommes;
    m_listeCouplesSauve = m_listeCouples;

    m_3btnCases.clear();
    ui->btnAide->setDisabled(false);

    m_message = trUtf8("Un nombre cible (foncé) est\nsomme des deux nombres clairs.\n\nChoisis les nombres par\ngroupe de trois de sorte\nqu'il n'en reste plus un seul.");
}

void MainWindow::attraperBtnCase()
{
    QObject * btnClique = sender();
    m_btnClique = btnClique->objectName();
    m_btnCases[m_btnClique.toInt()]->setFont(fontMEDIUM);
    if(m_isCanceled)
    {
         m_btnCases[m_btnClique.toInt()]->setCouleursTexte(QColor(0,108,192,255),QColor(0,108,192,255),QColor(0,108,192,255),QColor(0,108,192,255));
    }
    m_btnCases[m_btnClique.toInt()]->setDisabled(true);
    m_3btnCases << m_btnClique.toInt();
    if(m_3btnCases.size() == 3) verifier3();
    emit signalBtnCase(m_btnClique);
}

void MainWindow::verifier3() {
    bool contientSomme = false;
    for (int i = 0; i < 3; i++) {
        if(m_btnCases[m_3btnCases[i]]->styleSheet().contains("fondSomme"))
        {
            contientSomme = true;
        }
    }
    if(!contientSomme)
    {
        AbulEduMessageBoxV1 *box = new AbulEduMessageBoxV1(trUtf8("Problème !!"), trUtf8("Tu dois associer deux cases claires avec leur somme (nombre foncé), pas trois cases claires..."));
        box->show();
        for (int i = 0; i < 3; i++) {
            m_btnCases[m_3btnCases[i]]->setFont(fontBIG);
            m_btnCases[m_3btnCases[i]]->setDisabled(false);
        }
        m_3btnCases.clear();
        return;
    }
//    qDebug() << "verifier3" << m_3btnCases;
    QList<int> v; // liste des valeurs des 3 boutons
    BtnCase* sum;
    int maxi = -1;
    for (int i = 0; i < 3; i++)
    {
        if(m_btnCases[m_3btnCases[i]]->getMValeur() > maxi)
        {
            maxi = m_btnCases[m_3btnCases[i]]->getMValeur();
            sum = m_btnCases[m_3btnCases[i]];
        }
        v << m_btnCases[m_3btnCases[i]]->getMValeur();
    }
    qSort(v.begin(), v.end());
    if (v[0]+v[1]==v[2]) {
//        qDebug() << "j'enleve" << v[2] << v[0] << v[1];
        for (int i = 0; i < 3; i++) { // annuler les boutons
            m_btnCases[m_3btnCases[i]]->setFont(fontMEDIUM);
            m_btnCases[m_3btnCases[i]]->setDisabled(true);
            m_btnCases[m_3btnCases[i]]->setMChoisi(true);
            if(m_isCanceled)
            {
                if(m_btnCases[m_3btnCases[i]] == sum)
                {
                    m_btnCases[m_3btnCases[i]]->setIconeNormale(":/data_images/fondCorrectionSomme");
                }
                else
                {
                    m_btnCases[m_3btnCases[i]]->setIconeNormale(":/data_images/fondCorrection");
                }
            }
            else
            {
                if(m_btnCases[m_3btnCases[i]] == sum)
                {
                    m_btnCases[m_3btnCases[i]]->setIconeNormale(":/data_images/fondJuste");
                }
                else
                {
                    m_btnCases[m_3btnCases[i]]->setIconeNormale(":/data_images/fondJusteSomme");
                }
            }
            m_btnCases[m_3btnCases[i]]->setCouleursTexte(QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255));
        }
        // mettre à jour les listes "coup de pouce"
        m_listeSommes.removeOne(v[2]);
        m_listeCouples.removeOne(v[0]);
        m_listeCouples.removeOne(v[1]);

        m_3btnCases.clear();
        verifierTout();
    }
    else {
        for (int i = 0; i < 3; i++) { // restaurer les boutons
            m_btnCases[m_3btnCases[i]]->setFont(fontBIG);
            m_btnCases[m_3btnCases[i]]->setDisabled(false);
        }
        m_3btnCases.clear();
    }
}

void MainWindow::verifierTout() {
    int n = m_nLignes * m_nColonnes;
    for (int i = 0; i < m_nLignes * m_nColonnes; i++)
        if (m_btnCases[i]->getMChoisi()) n--;
    if(!m_isCanceled)
    {
        if (n == 0) {
            ui->btnAide->setDisabled(true);
            AbulEduMessageBoxV1 *box = new AbulEduMessageBoxV1(trUtf8("Félicitations !!"), trUtf8("Maintenant tu peux recommencer, choisir une nouvelle grille ou modifier les dimensions de la grille."));
            box->setWink();
            box->show();
        }
        else
        {
            AbulEduMessageBoxV1 *box = new AbulEduMessageBoxV1(trUtf8("Bien !!"), trUtf8("Encore %1").arg(QString::number(n/3)));
            box->setWink();
            box->show();
        }
    }
}

void MainWindow::on_btnRecommencer_clicked()
{
    m_isCanceled = false;
    for (int i = 0; i < m_nLignes * m_nColonnes; i++) {
        m_btnCases[i]->restaure();
        m_btnCases[i]->setFont(fontBIG);
        m_btnCases[i]->setDisabled(false);
        m_btnCases[i]->setMChoisi(false);
        if (m_btnCases[i]->getMSomme()) {
            m_btnCases[i]->setIconeNormale(":/data_images/fondSomme");
            m_btnCases[i]->setCouleursTexte(QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255));

        } else {
            m_btnCases[i]->setIconeNormale(":/data_images/fondNormal");
            m_btnCases[i]->setCouleursTexte(QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255),QColor(255,255,255,255));
        }
    }
    m_listeCouples = m_listeCouplesSauve;
    m_listeSommes = m_listeSommesSauve;
    m_3btnCases.clear();
    ui->btnAide->setDisabled(false);
}

void MainWindow::on_abeMenuFeuilleBtnNew_clicked()
{
    for (int i = 0; i < m_nLignes * m_nColonnes; i++) {
        m_btnCases[i]->setMValeur(-1);
    }
    initValeurs();
    m_3btnCases.clear();
    ui->btnAide->setDisabled(false);
    foreach(QTimer* t,findChildren<QTimer*>())
    {
        t->deleteLater();
    }
    setAllButtonsEnabled(true);
}

void MainWindow::_deleteBtnCases() {
    for (int i = 0; i < m_nLignes * m_nColonnes; i++)
        m_btnCases[i]->deleteLater();
    m_btnCases.clear();
}

void MainWindow::donneReponse()
{
    m_isCanceled = true;
    if(!m_listeSommes.isEmpty() && !m_listeCouples.isEmpty())
    {
        setAllButtonsEnabled(false);
        montreTierce();
        QTimer* attendre = new QTimer(this);
        attendre->setSingleShot(true);
        connect(attendre,SIGNAL(timeout()),this,SLOT(donneReponse()));
        attendre->start(2000);
    }
    else
    {
        setAllButtonsEnabled(true);
        return;
    }
}


void MainWindow::montreTierce()
{
    QListIterator<BtnCase*> iter(m_btnCasesSommes);
    bool trouve = false;
    while(iter.hasNext() && !trouve)
    {
        BtnCase* btn = iter.next();
        if(btn->getMValeur() == m_listeSommes.at(0))
        {
            trouve = true;
            btn->setCouleursTexte(QColor(0,108,192,255),QColor(0,108,192,255),QColor(0,108,192,255),QColor(0,108,192,255));
        }
    }
    QTimer::singleShot(500, trouveBoutonOu(m_listeCouples.at(0)), SLOT(click()));
    QTimer::singleShot(1000, trouveBoutonOu(m_listeCouples.at(1)), SLOT(click()));
    QTimer::singleShot(1500, trouveCibleOu(m_listeSommes.at(0)), SLOT(click()));
}

BtnCase *MainWindow::trouveBoutonOu(int valeur)
{
    bool trouve = false;
    BtnCase* leBon = new BtnCase();
    QListIterator<BtnCase*> iter(m_btnCasesNombres);
    while(iter.hasNext() && !trouve)
    {
        BtnCase* btn = iter.next();
        if(btn->getMValeur() == valeur)
        {
            leBon = btn;
            trouve = true;
            m_btnCasesNombres.removeOne(btn);
        }
    }
    return leBon;
}

BtnCase *MainWindow::trouveCibleOu(int valeur)
{
    qDebug()<<" trouveCibleOu : "<<valeur;
    bool trouve = false;
    BtnCase* leBon = new BtnCase();
    QListIterator<BtnCase*> iter(m_btnCasesSommes);
    while(iter.hasNext() && !trouve)
    {
        BtnCase* btn = iter.next();
        if(btn->getMValeur() == valeur)
        {
            leBon = btn;
            trouve = true;
            m_btnCasesSommes.removeOne(btn);
        }
    }
    return leBon;
}

void MainWindow::actionDIMxDIM(int nLignes, int nColonnes) {
    _deleteBtnCases();
    m_nLignes = nLignes;
    m_nColonnes = nColonnes;
    initGrille();
    initValeurs();
}

void MainWindow::on_action3x4_triggered() { actionDIMxDIM(3,4); }
void MainWindow::on_action3x5_triggered() { actionDIMxDIM(3,5); }
void MainWindow::on_action4x6_triggered() { actionDIMxDIM(4,6); }
void MainWindow::on_action5x6_triggered() { actionDIMxDIM(5,6); }

void MainWindow::on_btnAide_clicked()
{
    if(m_message.isEmpty())
    {
        //    qDebug() << "=== A l'aide ! ===" << m_listeSommes << m_listeCouples;
        QList<int> listeSommes;
        QList<int> listeCouples;
        listeSommes = m_listeSommes;
        listeCouples = m_listeCouples;
        int v2; // solution v2 = v0 + v1
        m_coupDePouce.clear();
        int nSommes = listeSommes.size();
        int k = 0; //degré de résolution (de 0 à n-1)
        bool possible2 = true;  // résolution possible
        // on veut : !possible ou k = nSommes
        while (possible2 && k < nSommes) {
            v2 = listeSommes[0];
            //        qDebug() << "possible2 ? " << k << v2 << listeSommes << listeCouples;
            //
            // je cherche v2
            //
            //        qDebug() << "je cherche v2 (start)" << v2;
            bool trouve = false;
            int nCouples = listeCouples.size();
            int v0, v1;
            int i = 0;
            // on veut trouve ou i >= nCouples
            while(!trouve && i < nCouples-1) {
                v0 = listeCouples[i];
                //            qDebug() << "rechercher complement a" << v0 << "pour" << v2;
                int j = i+1;
                while (!trouve && j < nCouples) {
                    v1 = listeCouples[j];
                    //                qDebug() << "  " << v0 << "+" << v1 << "?" << v2;
                    trouve =  (v2 == v0 + v1);
                    if (trouve) {
                        m_coupDePouce << v2 << v0 << v1;
                        //                    qDebug() << "\n++++++ trouve" << m_coupDePouce << "\n";
                    }
                    j++;
                }
                i++;
            }

            // trouve ?
            if (trouve) {
                listeSommes.removeOne(v2);
                listeCouples.removeOne(v0);
                listeCouples.removeOne(v1);
                //            qDebug() << "listes apres remove" << listeSommes << listeCouples;
                k++;
            } else {
                possible2 = false;
            }
        }
        //
        // conclusion
        //
        if (possible2) {
            if (m_listeSommes.size() <= m_listeSommesSauve.size()/2) { // pas d'aide si peu de sommes à chercher
                AbulEduMessageBoxV1 *box = new AbulEduMessageBoxV1(trUtf8("Désolé !!"),trUtf8("Termine sans aide..."));
                box->show();
            } else {
                AbulEduMessageBoxV1 *box = new AbulEduMessageBoxV1(trUtf8("Coup de pouce !!"),trUtf8("Essaye ")+QString::number(m_coupDePouce[0])+" = "+QString::number(m_coupDePouce[1])+" + "+QString::number(m_coupDePouce[2]));
                box->show();
            }
        } else {
            //        qDebug() << "Impossible " << listeSommes;
            AbulEduMessageBoxV1 *box = new AbulEduMessageBoxV1(trUtf8("Coup de pouce !!"),trUtf8("Peux-tu faire ")+QString::number(listeSommes.first())+trUtf8(" ?\n\nSi tu ne peux pas, recommence."));
            box->show();
        }
    }
    else
    {
        AbulEduMessageBoxV1 *box = new AbulEduMessageBoxV1(trUtf8("Coup de pouce !!"), m_message);
        box->show();
        m_message = QString();
    }
}

void MainWindow::_changeNiveau() {
    switch (m_niveau) {
        case 0 : actionDIMxDIM(3,4); break;
        case 1 : actionDIMxDIM(3,5); break;
        case 2 : actionDIMxDIM(4,6); break;
        case 3 : actionDIMxDIM(5,6); break;
    }
    ui->lblLevel->setPixmap(QPixmap(":/data_images/belt"+QString::number(m_niveau)));
    on_btnNiveauAnnuler_clicked();
}

void MainWindow::on_abeMenuFeuilleBtnQuit_clicked()
{
    close();
}

void MainWindow::on_abeMenuFeuilleBtnHelp_clicked()
{
    /* En attendant d'avoir avancé sur une nouvelle boite à propos, je vais ici appeler l'autre bouton aide, celui de la télécommande
    ui->stackedWidget->slideInWidget(ui->pageApropos); */
    on_btnAide_clicked();
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->slideInWidget(ui->pagePrincipale);
}

void MainWindow::on_btnAbandonner_clicked()
{
    on_btnRecommencer_clicked();
    donneReponse();
}

void MainWindow::on_btnNiveauNoire_clicked()
{
    m_niveau = 3;
    _changeNiveau();
}

void MainWindow::on_btnNiveauMarron_clicked()
{
    m_niveau = 2;
    _changeNiveau();
}

void MainWindow::on_btnNiveauOrange_clicked()
{
    m_niveau = 1;
    _changeNiveau();
}

void MainWindow::on_btnNiveauJaune_clicked()
{
    m_niveau = 0;
    _changeNiveau();
}

void MainWindow::on_btnNiveaux_clicked()
{
    ui->frmNiveau->setVisible(true);
    ui->frmNiveau->raise();
    ui->btnNiveaux->setStyleSheet(ui->btnNiveaux->styleSheet().replace("background-color:rgba(0,0,0,0);","border-radius:5px;background-color:#ffffff;"));
}

void MainWindow::on_btnNiveauAnnuler_clicked()
{
    ui->frmNiveau->setVisible(false);
    ui->btnNiveaux->setStyleSheet(ui->btnNiveaux->styleSheet().replace("border-radius:5px;background-color:#ffffff;","background-color:rgba(0,0,0,0);"));
}

void MainWindow::setAllButtonsEnabled(bool trueFalse)
{
    foreach(AbulEduFlatBoutonV1* enfant,ui->frmIcones->findChildren<AbulEduFlatBoutonV1 *>())
    {
        if(enfant->whatsThis() != "nombres" && enfant->whatsThis() != "verification")
          enfant->setEnabled(trueFalse);
    }
}

void MainWindow::slotChangeLangue(QString lang)
{
    qApp->removeTranslator(&qtTranslator);
    qApp->removeTranslator(&myappTranslator);

    //Un 1er qtranslator pour prendre les traductions QT Systeme
    //c'est d'ailleur grace a ca qu'on est en RTL
    qtTranslator.load("qt_" + lang, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    qApp->installTranslator(&qtTranslator);

    //foreach (QWidget *widget, QApplication::allWidgets()) widget->setLayoutDirection(Qt::RightToLeft);
    //Et un second qtranslator pour les traductions specifiques du
    //logiciel
    myappTranslator.load("leterrier-tierce_" + lang, "lang");
    qApp->installTranslator(&myappTranslator);
    ui->retranslateUi(this);
}
