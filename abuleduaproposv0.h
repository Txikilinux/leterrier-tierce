/** Implémentation Automatique du menu Aide
 *
 * @see https://redmine.ryxeo.com/projects/leterrier-developpeu/
 * @author 2010 Jean-Louis Frucot <frucot.jeanlouis@free.fr>
 * @see The GNU Public License (GPL)
 */

/**
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

#ifndef ABULEDUAPROPOS_H
#define ABULEDUAPROPOS_H


#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtXml/QDomDocument>

namespace Ui {
    class AbulEduAproposV0;
}

class AbulEduAproposV0 : public QDialog
{
    Q_OBJECT

public:
    explicit AbulEduAproposV0(QWidget *parent = 0);
    ~AbulEduAproposV0();
    QObject *w;

private:
    Ui::AbulEduAproposV0 *ui;
    void installeMenu();
    QDomDocument *xml;
    QString linkString;
    QString titleString;
    QString currentTag;
    QString itemTitre;
    QString itemDate;
    QString itemLink;
    QString itemDescription;
    QAction *actionAide;
    QAction *actionPeda;
    QAction *actionAideIntegree;
    QAction *actionForum;
    QAction *actionNews;
    QAction *actionTraductions;
    QAction *actionAbout;
    QNetworkAccessManager *m_nam;
    bool p_pedaDownloaded;
    bool p_forumDownloaded;
    bool p_newsDownloaded;
    QUrl abeBuildUrl(QString reflector, QString action);

private slots:
    void on_tabWidget_currentChanged(int index);
    void on_lblPosezVotreQuestion_linkActivated(QString link);
    void aide();
    void montreAide();
    void montrePeda();
    void montreNews();
    void montreForum();
    void montreTraduire();
    void montreAPropos();
    void changeTab(int onglet);
    void finishedSlotForum(QNetworkReply*);
    void finishedSlotNews(QNetworkReply*);
    void finishedSlotPeda(QNetworkReply*);
    void finishedSlotWPAD(QNetworkReply*);

signals:
    /** Demande le positionnement de l'onglet de l'aide
      * @param onglet : le numéro de l'onglet
      */
    void setindex(int onglet);
};

#endif // ABULEDUAPROPOS_H
