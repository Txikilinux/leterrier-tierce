/**
  * Tierce (le terrier d'AbulEdu)
  *
  * @warning aucun traitement d'erreur n'est pour l'instant implémenté
  * @see https://redmine.ryxeo.com/projects/
  * @author 2011 Andre Connes <andre dot connes at wanadoo dot fr>
  * @author 2011 Eric Seigne <eric.seigne@ryxeo.com> (qtranslator)
  * @see The GNU Public License (GPL)
  */

/*
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
    qDebug()<<"fin setupui";
    qDebug()<<ui->frmAireDeJeu->styleSheet();
    ui->frmAireDeJeu->setStyleSheet("QFrame#frmAireDeJeu {	\nbackground-image: url(:/data_images/cadreNombres);\nbackground-repeat: repeat-no;\nbackground-position: top right;\n}");
    ui->btnMinimized->setIconeNormale(":/data_images/showMinimized");
    ui->btnFullScreen->setIconeNormale(":/data_images/showMaximized");
    ui->verticalSpacer->changeSize(20,3,QSizePolicy::Fixed,QSizePolicy::Fixed);

    AbulEduAproposV0 *monAide=new AbulEduAproposV0(this);

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
    qDebug()<<"avant initgrille";
    qDebug()<<ui->frmAireDeJeu->pos();
    ui->frmAireDeJeu->raise();
    initGrille();
    qDebug()<<"fin initgrille";
//    ui->frmAireDeJeu->move(280,30);
    ui->frmAireDeJeu->setGeometry(400,20,500,480);

    qDebug()<<ui->frmAireDeJeu->pos();
    initValeurs();

    ui->menuBar->hide();

    //Une astuce pour eviter de faire 7 boutons * 3 lignes pour activer les icones
    QList<AbulEduFlatBoutonV1 *> btns = ui->frmIcones->findChildren<AbulEduFlatBoutonV1 *>();
    for(int i = 0; i < btns.count(); i++)
    {
        QString composant = btns.at(i)->whatsThis();
        btns.at(i)->setIconeNormale(QString(":/data_images/%1").arg(composant));

#ifdef __ABULEDUTABLETTEV1__MODE__
        btns.at(i)->setIconePressed(QString(":/data_images/%1Hover").arg(composant));
#else
        btns.at(i)->setIconeSurvol(QString(":/data_images/%1Hover").arg(composant));
#endif
        btns.at(i)->setIconeDisabled(QString(":/data_images/%1Disabled").arg(composant));
        btns.at(i)->setTexteAlignement(Qt::AlignLeft);
    }

#ifdef __ABULEDUTABLETTEV1__MODE__
    /// 15/01/2012 Icham -> mode tablette, pas de tooltips (pas de survol en mode tactile, et puis ça faisait des trucs bizarres parfois)
    /// 15/01/2013 iCHAM -> icones survol = icones normales
    // on cherche tous les enfants, et on leur met une chaine vide en tooltips (= desactivation)
    foreach (QWidget *obj, findChildren<QWidget*>()) {
        obj->setToolTip("");
//        if(dynamic_cast<AbulEduFlatBoutonV1*>(obj)){
//            dynamic_cast<AbulEduFlatBoutonV1*>(obj)->setIconeSurvol(dynamic_cast<AbulEduFlatBoutonV1*>(obj)->getIconeNormale());
//        }
    }
#endif
    foreach(AbulEduFlatBoutonV1* enfant,ui->frmIcones->findChildren<AbulEduFlatBoutonV1 *>())
    {
        enfant->setCouleurFondPressed(QColor(255,255,255,50));
        enfant->setCouleurTexteSurvol(Qt::red);
        enfant->setCouleurTexteNormale(Qt::white);
        enfant->setStyleSheet(enfant->styleSheet().replace("border-image","text-align: bottom;background-image"));
        enfant->setStyleSheet(enfant->styleSheet().replace("image-position: center","background-position: center top"));
    }

    /* Positionnement en dur puisque la hauteur de fenêtre "utile" est fixe */
    ui->frmNiveau->move(ui->frmIcones->x()-ui->frmNiveau->width()+8,ui->frmIcones->y()+19);
    ui->frmNiveau->setVisible(false);

    setWindowFlags(Qt::CustomizeWindowHint);

    ui->vl_widgetContainer->removeWidget(ui->frmButtons);
    ui->frmButtons->move(9,40);
    ui->frmButtons->setVisible(false);
    ui->frmButtons->adjustSize();

    ui->btnLanguages->setIconeNormale(":/data_flags/fr");
    ui->btnLanguages->setIconeSurvol(":/data_flags/frHover");
    ui->frmChoixLangues->move(790,0);
    ui->frmChoixLangues->setVisible(false);
    ui->btnIt->setVisible(false);
    ui->btnDe->setVisible(false);
    ui->btnOc->setVisible(false);
    ui->frmChoixLangues->adjustSize();
    foreach(AbulEduFlatBoutonV1* btn, ui->frmChoixLangues->findChildren<AbulEduFlatBoutonV1*>())
    {
        if(!btn->whatsThis().isEmpty())
        {
            connect(btn, SIGNAL(clicked()),SLOT(slotChangeLangue()),Qt::UniqueConnection);
        }
    }

#ifdef __ABULEDUTABLETTEV1__MODE__
    ui->btnMinimized->setVisible(false);
    ui->btnFullScreen->setVisible(false);
#else
    ui->btnMinimized->setCouleurFondSurvol(QColor(252,152,41));
    ui->btnMinimized->setCouleurFondPressed(QColor(252,152,41));
    ui->btnMinimized->setCouleurFondNormale(QColor(203,106,89));
    ui->btnMinimized->setAllMargins(8,4,8,12);
    ui->btnMinimized->setBorderRadius(4);
    ui->btnFullScreen->setCouleurFondSurvol(QColor(252,152,41));
    ui->btnFullScreen->setCouleurFondPressed(QColor(252,152,41));
    ui->btnFullScreen->setCouleurFondNormale(QColor(203,106,89));
    ui->btnFullScreen->setAllMargins(8,12,8,4);
    ui->btnFullScreen->setBorderRadius(4);
#endif

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

void MainWindow::on_btnNouveau_clicked()
{
    for (int i = 0; i < m_nLignes * m_nColonnes; i++) {
        m_btnCases[i]->setMValeur(-1);
    }
    initValeurs();
    m_3btnCases.clear();
    ui->btnAide->setDisabled(false);
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
        QTimer* attendre = new QTimer();
        attendre->setSingleShot(true);
        connect(attendre,SIGNAL(timeout()),this,SLOT(donneReponse()));
        attendre->start(5000);
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
    QTimer::singleShot(1000, trouveBoutonOu(m_listeCouples.at(0)), SLOT(click()));
    QTimer::singleShot(2000, trouveBoutonOu(m_listeCouples.at(1)), SLOT(click()));
    QTimer::singleShot(3000, trouveCibleOu(m_listeSommes.at(0)), SLOT(click()));
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

/* A priori scories à détruire
void MainWindow::on_btnUp_clicked()
{
    if (m_niveau < m_niveauMAX) m_niveau++;
    _changeNiveau();
}

void MainWindow::on_btnDown_clicked()
{
    if (m_niveau > 0) m_niveau--;
    _changeNiveau();
} */

void MainWindow::on_btnSortie_clicked()
{
    close();
}

void MainWindow::on_btnAideFeuille_clicked()
{
    ui->stackedWidget->slideInWidget(ui->pageApropos);
    on_btnFeuille_clicked();
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->slideInWidget(ui->pagePrincipale);
}
void MainWindow::on_btnFeuille_clicked()
{
    if (ui->frmButtons->isVisible())
    {
        ui->frmButtons->setVisible(false);
    }
    else
    {
        ui->frmButtons->setVisible(true);
        ui->frmButtons->raise();
    }
    on_btnNiveauAnnuler_clicked();
    on_btnLangueAnnuler_clicked();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    foreach(AbulEduFlatBoutonV1* enfant,ui->frmButtons->findChildren<AbulEduFlatBoutonV1 *>())
    {
        enfant->setCouleurTexteSurvol(Qt::red);
        enfant->setStyleSheet(enfant->styleSheet().replace("border-image","text-align: bottom;background-image"));
        enfant->setStyleSheet(enfant->styleSheet().replace("image-position: center","background-position: center top"));
    }
    ui->btnFeuille->setStyleSheet("QPushButton > *{color:red;}QPushButton{border: none; color:rgba(0,0,0,255);background-repeat: no-repeat;background-color:transparent;}");

}

#ifndef __ABULEDUTABLETTEV1__MODE__
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isWindowMoving) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && ui->lblTitre->rect().contains(event->pos())) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
        m_isWindowMoving = true;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_isWindowMoving = false;
}
#endif

void MainWindow::on_btnDebut_clicked()
{

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
    if (ui->frmButtons->isVisible())
    {
        ui->frmButtons->setVisible(false);
    }
    on_btnLangueAnnuler_clicked();
}

void MainWindow::on_btnNiveauAnnuler_clicked()
{
    ui->frmNiveau->setVisible(false);
    ui->btnNiveaux->setStyleSheet(ui->btnNiveaux->styleSheet().replace("border-radius:5px;background-color:#ffffff;","background-color:rgba(0,0,0,0);"));
}


void MainWindow::on_btnMinimized_clicked()
{
    showMinimized();
}

void MainWindow::on_btnFullScreen_clicked()
{
    if(isFullScreen())
    {
        showNormal();
        ui->centralWidget->move(0,0);
        ui->widgetContainer->move(0,0);
        ui->btnFullScreen->setIconeNormale(":/data_images/showMaximized");
    }
    else
    {
        QDesktopWidget *widget = QApplication::desktop();
        int desktop_width = widget->width();
        int desktop_height = widget->height();
//        this->move((desktop_width-this->width())/2, (desktop_height-this->height())/2);
        ui->centralWidget->move((desktop_width-ui->centralWidget->width())/2, (desktop_height-ui->centralWidget->height())/2);
        ui->widgetContainer->move((desktop_width-ui->widgetContainer->width())/2, (desktop_height-ui->widgetContainer->height())/2);
        showFullScreen();
        ui->btnFullScreen->setIconeNormale(":/data_images/showNormal");
    }
}

void MainWindow::on_btnLanguages_clicked()
{
    ui->frmChoixLangues->setVisible(true);
    ui->frmChoixLangues->raise();
    if (ui->frmButtons->isVisible())
    {
        ui->frmButtons->setVisible(false);
    }
    on_btnNiveauAnnuler_clicked();
}

void MainWindow::on_btnFr_clicked()
{
    ui->btnLanguages->setIconeNormale(":/data_flags/fr");
    ui->btnLanguages->setIconeSurvol(":/data_flags/frHover");
    ui->frmChoixLangues->setVisible(false);
}

void MainWindow::on_btnEn_clicked()
{
    ui->btnLanguages->setIconeNormale(":/data_flags/en");
    ui->btnLanguages->setIconeSurvol(":/data_flags/enHover");
    ui->frmChoixLangues->setVisible(false);
}

void MainWindow::on_btnEs_clicked()
{
    ui->btnLanguages->setIconeNormale(":/data_flags/es");
    ui->btnLanguages->setIconeSurvol(":/data_flags/esHover");
    ui->frmChoixLangues->setVisible(false);
}

void MainWindow::on_btnIt_clicked()
{
    ui->btnLanguages->setIconeNormale(":/data_flags/it");
    ui->btnLanguages->setIconeSurvol(":/data_flags/itHover");
    ui->frmChoixLangues->setVisible(false);
}

void MainWindow::on_btnDe_clicked()
{
    ui->btnLanguages->setIconeNormale(":/data_flags/de");
    ui->btnLanguages->setIconeSurvol(":/data_flags/deHover");
    ui->frmChoixLangues->setVisible(false);
}

void MainWindow::on_btnOc_clicked()
{
    ui->btnLanguages->setIconeNormale(":/data_flags/oc");
    ui->btnLanguages->setIconeSurvol(":/data_flags/ocHover");
    ui->frmChoixLangues->setVisible(false);
}

void MainWindow::on_btnLangueAnnuler_clicked()
{
    ui->frmChoixLangues->setVisible(false);
}

void MainWindow::slotChangeLangue()
{
    QString lang = static_cast<AbulEduFlatBoutonV1*>(sender())->whatsThis();
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

void MainWindow::setAllButtonsEnabled(bool trueFalse)
{
    foreach(AbulEduFlatBoutonV1* enfant,ui->frmTop->findChildren<AbulEduFlatBoutonV1 *>())
    {
        enfant->setEnabled(trueFalse);
    }
    foreach(AbulEduFlatBoutonV1* enfant,ui->frmIcones->findChildren<AbulEduFlatBoutonV1 *>())
    {
        if(enfant->whatsThis() != "nombres" && enfant->whatsThis() != "verification")
          enfant->setEnabled(trueFalse);
    }
}
