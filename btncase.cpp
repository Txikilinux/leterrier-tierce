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


#include "btncase.h"

BtnCase::BtnCase(QWidget *parent) :
    QPushButton(parent)
{
}

BtnCase::BtnCase(int rang, QWidget *parent) :
    QPushButton(parent)
{
    m_rang = rang;
    m_valeur = -1;
    m_somme = false;
    m_choisi = false;
    setStyleSheet("background-color: "+NORMALBTN+"; border-width: 3px; border-style: solid; border-color: grey; border-radius : 8px; color: darkgreen; font-weight: bold");
}

int BtnCase::getMValeur() { return m_valeur; }
void BtnCase::setMValeur(int n) { m_valeur = n; }
void BtnCase::setMSauve() { m_sauve = m_valeur; }
void BtnCase::restaure() { m_valeur = m_sauve; }
bool BtnCase::getMSomme() { return m_somme; }
void BtnCase::setMSomme(bool somme) { m_somme = somme; }
bool BtnCase::getMChoisi() { return m_choisi; }
void BtnCase::setMChoisi(bool choisi) { m_choisi = choisi; }
