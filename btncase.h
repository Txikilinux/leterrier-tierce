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


#ifndef BTNCASE_H
#define BTNCASE_H

#include <QWidget>
#include <QPushButton>
#include <QColor>

const QString SUMBTN = "#FFB0B0";      //couleur bouton somme
const QString NORMALBTN = "#FFFF00";   // couleur bouton normal
const QString NEUTRALBTN = "#B0E0B0";  // couleur bouton neutre
const QString ERRORBTN = "#F02020";    // couleur bouton erronné

class BtnCase : public QPushButton
{
    Q_OBJECT
public:
    explicit BtnCase(QWidget *parent = 0);
    BtnCase(int rang, QWidget *parent = 0);
    int getMValeur();
    void setMValeur(int n);
//    int getMSauve();
    void setMSauve();
    void restaure(); // pour restaurer la valeur unitiale du bouton
    bool getMSomme();
    void setMSomme(bool somme);
    bool getMChoisi();
    void setMChoisi(bool choisi);

private:
    int m_rang;
    int m_valeur;
    int m_sauve; // attribut utilisé pour la restauration d'une grille
    bool m_somme;  // vrai si ce bouton est somme de 2 autres
    bool m_choisi;


signals:

public slots:

};

#endif // BTNCASE_H
