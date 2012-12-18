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

    AbulEduAproposV0 *monAide=new AbulEduAproposV0(this);

    fontBIG.setPointSize(35);
    fontMEDIUM.setPointSize(20);
    fontMINUS.setPointSize(10);

    // défaut
    m_niveau = 0;
    m_niveauMAX = 3;
    m_nLignes = 3;
    m_nColonnes = 4;

    initGrille();
    initValeurs();

#ifdef __ABULEDUTABLETTEV1__MODE__
    ui->menuBar->hide();
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGrille() {
    int w = ((LARGEUR-200) / m_nColonnes);   // largeur max des cases
    int h = (HAUTEUR / m_nLignes);     // hauteur max des cases
    int dimCase = ((w < h)? w : h)-3;   // dim des cases
    for (int i = 0; i < m_nLignes; i++) {
        for (int j = 0; j < m_nColonnes; j++) {
//            QString n = QString::number(i*m_nColonnes +j);
            int n = i*m_nColonnes +j;
            BtnCase *btnCase = new BtnCase(n, ui->centralWidget);
            btnCase->setObjectName(QString::number(n)); // On donne un nom : #
            btnCase->setGeometry(DW+(dimCase+2)*j,DH+(dimCase+2)*i,dimCase,dimCase);
            btnCase->setVisible(true);
            m_btnCases.append(btnCase);
            connect(btnCase, SIGNAL(clicked()),this,SLOT(attraperBtnCase())); //on connecte le bouton au slot
        }
    }
}

void MainWindow::initValeurs() {

    int nBtn = m_nLignes * m_nColonnes;
    int encore = nBtn;
    QList<int> listeTirage; // ensemble des valeurs v1 et v2 pour éviter les répétitions dans somme = v1 + v2
    m_listeSommes.clear();
    m_listeCouples.clear();
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
        m_btnCases[n1]->setStyleSheet("background-color: "+NORMALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
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
        m_btnCases[n2]->setStyleSheet("background-color: "+NORMALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
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
        m_btnCases[n]->setStyleSheet("background-color: "+SUMBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
        m_listeSommes << v1+v2;
        encore--;
    }
    // sauvegarde des listes "coup de pouce" pour pouvoir aider avec RECOMMENCER
    m_listeSommesSauve = m_listeSommes;
    m_listeCouplesSauve = m_listeCouples;

    m_3btnCases.clear();
    ui->btnAide->setDisabled(false);
    ui->tedAffiche->setText(trUtf8("Un pion rose est\nsomme des deux pions jaunes.\n\nChoisis les pions par\ngroupe de trois de sorte\nqu'il n'en reste plus un seul."));
}

void MainWindow::attraperBtnCase()
{
    QObject * btnClique = sender();
    m_btnClique = btnClique->objectName();
    m_btnCases[m_btnClique.toInt()]->setFont(fontMINUS);
    m_btnCases[m_btnClique.toInt()]->setDisabled(true);
    m_3btnCases << m_btnClique.toInt();
    if(m_3btnCases.size() == 3) verifier3();
    emit signalBtnCase(m_btnClique);
}

void MainWindow::verifier3() {
//    qDebug() << "verifier3" << m_3btnCases;
    QList<int> v; // liste des valeurs des 3 boutons
    for (int i = 0; i < 3; i++)
        v << m_btnCases[m_3btnCases[i]]->getMValeur();
    qSort(v.begin(), v.end());
    if (v[0]+v[1]==v[2]) {
//        qDebug() << "j'enleve" << v[2] << v[0] << v[1];
        for (int i = 0; i < 3; i++) { // annuler les boutons
            m_btnCases[m_3btnCases[i]]->setFont(fontMINUS);
            m_btnCases[m_3btnCases[i]]->setDisabled(true);
            m_btnCases[m_3btnCases[i]]->setMChoisi(true);
            m_btnCases[m_3btnCases[i]]->setStyleSheet("background-color: "+NEUTRALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
        }
        // mettre à jour les listes "coup de pouce"
        m_listeSommes.removeOne(v[2]);
        m_listeCouples.removeOne(v[0]);
        m_listeCouples.removeOne(v[1]);

        m_3btnCases.clear();
        verifierTout();
    } else {
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
    if (n == 0) {
        ui->btnAide->setDisabled(true);
        ui->tedAffiche->setText(trUtf8("Bravo, maintenant tu peux :\n\n- recommencer ;\n- choisir une nouvelle grille ;\n- modifier les dimensions de la grille."));
    } else
        ui->tedAffiche->setText("\n\n"+trUtf8("Encore ")+QString::number(n/3));
}

void MainWindow::on_btnRecommencer_clicked()
{
    for (int i = 0; i < m_nLignes * m_nColonnes; i++) {
        m_btnCases[i]->restaure();
        m_btnCases[i]->setFont(fontBIG);
        m_btnCases[i]->setDisabled(false);
        m_btnCases[i]->setMChoisi(false);
        if (m_btnCases[i]->getMSomme()) {
            m_btnCases[i]->setStyleSheet("background-color: "+SUMBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");

        } else {
            m_btnCases[i]->setStyleSheet("background-color: "+NORMALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
        }
    }
    m_listeCouples = m_listeCouplesSauve;
    m_listeSommes = m_listeSommesSauve;
    m_3btnCases.clear();
    ui->btnAide->setDisabled(false);
    ui->tedAffiche->setText(trUtf8("Un pion rose est\nsomme des deux pions jaunes.\n\nChoisis les pions par\ngroupe de trois de sorte\nqu'il n'en reste plus un seul."));
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
            ui->tedAffiche->setText("\n\n"+trUtf8("Désolé, termine sans aide..."));
        } else {
            ui->tedAffiche->setText("\n\n"+trUtf8("Essaye ")+QString::number(m_coupDePouce[0])+" = "+QString::number(m_coupDePouce[1])+" + "+QString::number(m_coupDePouce[2]));
        }
    } else {
//        qDebug() << "Impossible " << listeSommes;
        ui->tedAffiche->setText("\n\n"+trUtf8("Peux-tu faire ")+QString::number(listeSommes.first())+trUtf8(" ?\n\nSi tu ne peux pas, recommence."));
    }
}

void MainWindow::_changeNiveau() {
    switch (m_niveau) {
        case 0 : actionDIMxDIM(3,4); break;
        case 1 : actionDIMxDIM(3,5); break;
        case 2 : actionDIMxDIM(4,6); break;
        case 3 : actionDIMxDIM(5,6); break;
    }
}

void MainWindow::on_btnUp_clicked()
{
    if (m_niveau < m_niveauMAX) m_niveau++;
    _changeNiveau();
}

void MainWindow::on_btnDown_clicked()
{
    if (m_niveau > 0) m_niveau--;
    _changeNiveau();
}
