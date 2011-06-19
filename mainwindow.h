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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QList>
#include <QTranslator>
#include <QLibraryInfo>
#include "btncase.h"
#include "abuleduaproposv0.h"

const int LARGEUR = 1024-100;
const int HAUTEUR = 600-100;
const int DW = 20;          // décalage colonne de gauche
const int DH = 40;          // décalage ligne du haut


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getMBtnClique();

private:
    Ui::MainWindow *ui;
    void actionDIMxDIM(int nLignes, int nColonnes);
    void _changeNiveau();
    void initGrille();
    void initValeurs();
    void verifier3();
    void verifierTout();
    void _deleteBtnCases();

    //le traducteur d'interface
    QTranslator qtTranslator;
    QTranslator myappTranslator;

    // le produit lignes x colonnes doit être multiple de 3
    int m_nLignes;
    int m_nColonnes;
    int m_niveau; // 0 = 3x4, 1 = 3x5, 2 = 4x6, 3 = 5x6
    int m_niveauMAX;
    QString m_btnClique;
    QList<BtnCase *> m_btnCases;
    QList<int> m_3btnCases; // indice des 3 boutons sélectionnés

    // pour le coup de pouce : Somme = X + Y
    QList<int> m_listeSommes;  // Somme
    QList<int> m_listeSommesSauve;
    QList<int> m_listeCouples; // liste des entiers X et Y (pas les couples)
    QList<int> m_listeCouplesSauve;

    QList<int> m_coupDePouce; // une solution particulière

    /**
      fontes utilisées
    */
    QFont fontBIG; // 35
    QFont fontMEDIUM; // 25
    QFont fontMINUS; //10

signals:
    /**
      signal émis lorsque on clique sur un bouton
      */
    void signalBtnCase(QString);

private slots:
    /**
      retrouver le btnCase qui a émis le signal et traiter ce signal
      */
    void on_btnDown_clicked();
    void on_btnUp_clicked();
    void on_btnAide_clicked();
    void on_action5x6_triggered();
    void on_action4x6_triggered();
    void on_action3x5_triggered();
    void on_action3x4_triggered();
    void on_btnNouveau_clicked();
    void on_btnRecommencer_clicked();
    void attraperBtnCase();
};

#endif // MAINWINDOW_H
