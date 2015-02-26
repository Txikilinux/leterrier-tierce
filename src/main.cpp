/**
  * Tierce (le Terrier d'AbulÉdu)
  *
  * @warning aucun traitement d'erreur n'est pour l'instant implémenté
  * @see https://redmine.ryxeo.com/projects/leterrier-fubuki
  * @author 2011 André Connes <andre.connes@wanadoo.fr>
  * @author 2011-2015 Eric Seigne <eric.seigne@ryxeo.com>
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


#include "version.h"
#include "mainwindow.h"
#include "abuleduapplicationv1.h"

int main(int argc, char *argv[])
{
    AbulEduApplicationV1 a(argc, argv,VER_INTERNALNAME_STR, VER_PRODUCTVERSION_STR, VER_COMPANYDOMAIN_STR, VER_COMPANYNAME_STR);
    a.setAbeApplicationLongName(QObject::trUtf8(VER_PRODUCTNAME_STR));

    MainWindow w;

    // ça sert à rien vu qu'il y a un fixedSize() au dimension de la tablette
#ifdef __ABULEDUTABLETTEV1__MODE__
    w.showFullScreen();
#else
    w.show();
#endif

    return a.exec();
}
