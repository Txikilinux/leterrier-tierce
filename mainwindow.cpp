/**
  * Tierce (le terrier d'AbulEdu)
  *
  * @warning aucun traitement d'erreur n'est pour l'instant implémenté
  * @see https://redmine.ryxeo.com/projects/
  * @author 2011 Andre Connes <andre dot connes at wanadoo dot fr>
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
    ui->setupUi(this);

    AbulEduAproposV0 *monAide=new AbulEduAproposV0(this);

    fontBIG.setPointSize(35);
    fontMEDIUM.setPointSize(20);
    fontMINUS.setPointSize(10);

    // défaut
    m_nLignes = 3;
    m_nColonnes = 4;

    initGrille();
    initValeurs();
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
    while (encore > 0) {
        int n1, v1;
        do {
            n1 = rand() % nBtn;
        } while (m_btnCases[n1]->getMValeur() > -1);
        v1 = 1+rand() %nBtn;
        m_btnCases[n1]->setMValeur(v1);
        m_btnCases[n1]->setMSauve();
        m_btnCases[n1]->setText(QString::number(v1));
        m_btnCases[n1]->setMSomme(false);
        m_btnCases[n1]->setFont(fontBIG);
        m_btnCases[n1]->setDisabled(false);
        m_btnCases[n1]->setMChoisi(false);
        m_btnCases[n1]->setStyleSheet("background-color: "+NORMALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
        encore--;
        int n2, v2;
        do {
            n2 = rand() % nBtn;
        } while (m_btnCases[n2]->getMValeur() > -1);
        v2 = 1+rand() %nBtn;
        m_btnCases[n2]->setMValeur(v2);
        m_btnCases[n2]->setMSauve();
        m_btnCases[n2]->setText(QString::number(v2));
        m_btnCases[n2]->setMSomme(false);
        m_btnCases[n2]->setFont(fontBIG);
        m_btnCases[n2]->setDisabled(false);
        m_btnCases[n2]->setMChoisi(false);
        m_btnCases[n2]->setStyleSheet("background-color: "+NORMALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
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
        encore--;
    }

    m_3btnCases.clear();
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
    qDebug() << "verifier3" << m_3btnCases;
    QList<int> v; // liste des valeurs des 3 boutons
    for (int i = 0; i < 3; i++)
        v << m_btnCases[m_3btnCases[i]]->getMValeur();
    qSort(v.begin(), v.end());
    qDebug() << "valeurs " << v;
    if (v[0]+v[1]==v[2]) {
        for (int i = 0; i < 3; i++) { // annuler les boutons
            m_btnCases[m_3btnCases[i]]->setFont(fontMINUS);
            m_btnCases[m_3btnCases[i]]->setDisabled(true);
            m_btnCases[m_3btnCases[i]]->setMChoisi(true);
            m_btnCases[m_3btnCases[i]]->setStyleSheet("background-color: "+NEUTRALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
        }
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
    if (n == 0)
        ui->tedAffiche->setText(trUtf8("Bravo, maintenant tu peux :\n\n- recommencer ;\n- choisir une nouvelle grille ;\n- modifier les dimensions de la grille."));
    else
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
    m_3btnCases.clear();
}

void MainWindow::on_btnNouveau_clicked()
{
    for (int i = 0; i < m_nLignes * m_nColonnes; i++) {
        m_btnCases[i]->setMValeur(-1);
    }
    initValeurs();
    m_3btnCases.clear();
}

void MainWindow::_deleteBtnCases() {
    for (int i = 0; i < m_nLignes * m_nColonnes; i++)
        m_btnCases[i]->deleteLater();
    m_btnCases.clear();
}

void MainWindow::on_action3x4_triggered()
{
    _deleteBtnCases();
    m_nLignes = 3;
    m_nColonnes = 4;
    initGrille();
    initValeurs();
}

void MainWindow::on_action3x5_triggered()
{
    _deleteBtnCases();
    m_nLignes = 3;
    m_nColonnes = 5;
    initGrille();
    initValeurs();
}

void MainWindow::on_action4x6_triggered()
{
    _deleteBtnCases();
    m_nLignes = 4;
    m_nColonnes = 6;
    initGrille();
    initValeurs();
}

void MainWindow::on_action5x6_triggered()
{
    _deleteBtnCases();
    m_nLignes = 5;
    m_nColonnes = 6;
    initGrille();
    initValeurs();
}
