/********************************************************************************
** Form generated from reading UI file 'abuleduaproposv0.ui'
**
** Created: Sun Mar 13 22:34:55 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABULEDUAPROPOSV0_H
#define UI_ABULEDUAPROPOSV0_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AbulEduAproposV0
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabAide;
    QGridLayout *gridLayout_5;
    QGridLayout *gridAide;
    QTextBrowser *textAide;
    QWidget *tabRessources;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QTextBrowser *textAide_2;
    QWidget *tabNews;
    QGridLayout *gridLayout_4;
    QGridLayout *gridNews;
    QTextBrowser *textNews;
    QWidget *tabForum;
    QGridLayout *gridLayout_6;
    QGridLayout *gridForum;
    QTextBrowser *textForum;
    QLabel *lblPosezVotreQuestion;
    QWidget *tabTranslate;
    QGridLayout *gridLayout_7;
    QGridLayout *GridTranslate;
    QTextBrowser *textTranslate;
    QWidget *tabAbout;
    QGridLayout *gridLayout_8;
    QGridLayout *gridAbout;
    QTextBrowser *textAbout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerRight;
    QPushButton *pushButtonFermer;
    QSpacerItem *spacerLeft;

    void setupUi(QDialog *AbulEduAproposV0)
    {
        if (AbulEduAproposV0->objectName().isEmpty())
            AbulEduAproposV0->setObjectName(QString::fromUtf8("AbulEduAproposV0"));
        AbulEduAproposV0->resize(588, 411);
        verticalLayout = new QVBoxLayout(AbulEduAproposV0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(AbulEduAproposV0);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMouseTracking(false);
        tabAide = new QWidget();
        tabAide->setObjectName(QString::fromUtf8("tabAide"));
        gridLayout_5 = new QGridLayout(tabAide);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridAide = new QGridLayout();
        gridAide->setObjectName(QString::fromUtf8("gridAide"));
        textAide = new QTextBrowser(tabAide);
        textAide->setObjectName(QString::fromUtf8("textAide"));
        textAide->setSizeIncrement(QSize(0, 5));
        textAide->setSearchPaths(QStringList());
        textAide->setOpenExternalLinks(true);

        gridAide->addWidget(textAide, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridAide, 0, 0, 1, 1);

        tabWidget->addTab(tabAide, QString());
        tabRessources = new QWidget();
        tabRessources->setObjectName(QString::fromUtf8("tabRessources"));
        gridLayout_3 = new QGridLayout(tabRessources);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textAide_2 = new QTextBrowser(tabRessources);
        textAide_2->setObjectName(QString::fromUtf8("textAide_2"));
        textAide_2->setSizeIncrement(QSize(0, 5));
        textAide_2->setSearchPaths(QStringList());
        textAide_2->setOpenExternalLinks(true);

        gridLayout_2->addWidget(textAide_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tabRessources, QString());
        tabNews = new QWidget();
        tabNews->setObjectName(QString::fromUtf8("tabNews"));
        tabNews->setEnabled(true);
        gridLayout_4 = new QGridLayout(tabNews);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridNews = new QGridLayout();
        gridNews->setObjectName(QString::fromUtf8("gridNews"));
        textNews = new QTextBrowser(tabNews);
        textNews->setObjectName(QString::fromUtf8("textNews"));
        textNews->setStyleSheet(QString::fromUtf8("h1{color: rgb(255, 0, 0);}"));
        textNews->setOpenExternalLinks(true);

        gridNews->addWidget(textNews, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridNews, 0, 0, 1, 1);

        tabWidget->addTab(tabNews, QString());
        tabForum = new QWidget();
        tabForum->setObjectName(QString::fromUtf8("tabForum"));
        gridLayout_6 = new QGridLayout(tabForum);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridForum = new QGridLayout();
        gridForum->setObjectName(QString::fromUtf8("gridForum"));
        textForum = new QTextBrowser(tabForum);
        textForum->setObjectName(QString::fromUtf8("textForum"));
        textForum->setOpenExternalLinks(true);

        gridForum->addWidget(textForum, 0, 0, 1, 2);

        lblPosezVotreQuestion = new QLabel(tabForum);
        lblPosezVotreQuestion->setObjectName(QString::fromUtf8("lblPosezVotreQuestion"));
        lblPosezVotreQuestion->setTextFormat(Qt::RichText);
        lblPosezVotreQuestion->setTextInteractionFlags(Qt::TextBrowserInteraction);

        gridForum->addWidget(lblPosezVotreQuestion, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridForum, 0, 0, 1, 1);

        tabWidget->addTab(tabForum, QString());
        tabTranslate = new QWidget();
        tabTranslate->setObjectName(QString::fromUtf8("tabTranslate"));
        gridLayout_7 = new QGridLayout(tabTranslate);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        GridTranslate = new QGridLayout();
        GridTranslate->setObjectName(QString::fromUtf8("GridTranslate"));
        textTranslate = new QTextBrowser(tabTranslate);
        textTranslate->setObjectName(QString::fromUtf8("textTranslate"));

        GridTranslate->addWidget(textTranslate, 0, 0, 1, 1);


        gridLayout_7->addLayout(GridTranslate, 0, 0, 1, 1);

        tabWidget->addTab(tabTranslate, QString());
        tabAbout = new QWidget();
        tabAbout->setObjectName(QString::fromUtf8("tabAbout"));
        gridLayout_8 = new QGridLayout(tabAbout);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridAbout = new QGridLayout();
        gridAbout->setObjectName(QString::fromUtf8("gridAbout"));
        textAbout = new QTextBrowser(tabAbout);
        textAbout->setObjectName(QString::fromUtf8("textAbout"));
        QPalette palette;
        QBrush brush(QColor(239, 235, 231, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        textAbout->setPalette(palette);
        textAbout->setFrameShape(QFrame::NoFrame);
        textAbout->setFrameShadow(QFrame::Plain);
        textAbout->setLineWidth(0);
        textAbout->setMidLineWidth(0);
        textAbout->setOpenExternalLinks(true);

        gridAbout->addWidget(textAbout, 0, 1, 2, 1);

        label = new QLabel(tabAbout);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("data/images/will-win.png")));

        gridAbout->addWidget(label, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridAbout, 0, 0, 1, 1);

        tabWidget->addTab(tabAbout, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerRight);

        pushButtonFermer = new QPushButton(AbulEduAproposV0);
        pushButtonFermer->setObjectName(QString::fromUtf8("pushButtonFermer"));
        pushButtonFermer->setAutoFillBackground(false);

        horizontalLayout->addWidget(pushButtonFermer);

        spacerLeft = new QSpacerItem(28, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerLeft);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AbulEduAproposV0);
        QObject::connect(pushButtonFermer, SIGNAL(clicked()), AbulEduAproposV0, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AbulEduAproposV0);
    } // setupUi

    void retranslateUi(QDialog *AbulEduAproposV0)
    {
        AbulEduAproposV0->setWindowTitle(QApplication::translate("AbulEduAproposV0", "A Propos du logiciel", 0, QApplication::UnicodeUTF8));
        textAide->setHtml(QApplication::translate("AbulEduAproposV0", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Aide Calculette</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#00007f;\">R\303\250gle du jeu :</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#00007f;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; m"
                        "argin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">Sachant qu'un </span><span style=\" color:#ff007f;\">pion rose</span><span style=\" color:#00007f;\"> est la somme de deux </span><span style=\" color:#ff5500;\">pions jaunes</span><span style=\" color:#00007f;\">,</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">faites des groupes de trois pions</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">(</span><span style=\" color:#ff007f;\">un rose</span><span style=\" color:#00007f;\"> et </span><span style=\" color:#ff5500;\">deux jaunes</span><span style=\" color:#00007f;\">)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">de sorte qu'il n'en reste plus un seul.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#00007f;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#00007f;\">Dimensions :</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#00007f;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">Le menu </span><span style=\" font-weight:600; color:#00007f;\">Dimensions</span><span style=\" color:#00007f;\"> permet de choisi"
                        "r diff\303\251rentes grilles</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">fonction du nombre de lignes, de colonnes.</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabAide), QApplication::translate("AbulEduAproposV0", "Aide int\303\251gr\303\251e", 0, QApplication::UnicodeUTF8));
        textAide_2->setHtml(QApplication::translate("AbulEduAproposV0", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Aide Calculette</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\">Le flux RSS en provenance de libre pedagosite sera automatiquement t\303\251l\303\251charg\303\251 lors du lancement de l'application, ne touchez \303\240 rien de cette fen\303\252tre.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px; font-family:'DejaVu Sans';\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\">Exemple: http://libre.pedagosite.net/search/leterrier-tierce</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabRessources), QApplication::translate("AbulEduAproposV0", "Ressources", 0, QApplication::UnicodeUTF8));
        textNews->setHtml(QApplication::translate("AbulEduAproposV0", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\">Le flux RSS en provenance du redmine sera automatiquement t\303\251l\303\251charg\303\251 lors du lancement de l'application, ne touchez \303\240 rien de cette fen\303\252tre.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'DejaVu Sa"
                        "ns';\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\">Exemple: http://redmine.ryxeo.com/projects/leterrier-tierce/news</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabNews), QApplication::translate("AbulEduAproposV0", "Nouveaut\303\251s", 0, QApplication::UnicodeUTF8));
        textForum->setHtml(QApplication::translate("AbulEduAproposV0", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\">Le flux RSS en provenance du forum abuledu sera automatiquement t\303\251l\303\251charg\303\251 lors du lancement de l'application, ne touchez \303\240 rien de cette fen\303\252tre.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Dej"
                        "aVu Sans';\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\">Exemple: http://forum.abuledu.org/rss/topic/leterrier-tierce/lang/fr</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        lblPosezVotreQuestion->setText(QApplication::translate("AbulEduAproposV0", "Posez votre question sur le forum des utilisateurs ...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabForum), QApplication::translate("AbulEduAproposV0", "Forum", 0, QApplication::UnicodeUTF8));
        textTranslate->setHtml(QApplication::translate("AbulEduAproposV0", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:10pt;\">Vous appr\303\251ciez les logiciels d'Abul\303\211du et vous souhaitez nous aider \303\240 en d\303\251velopper d'autres et am\303\251liorer ceux qui existent d\303\251j\303\240 ?</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-fami"
                        "ly:'Sans'; font-size:10pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:10pt;\">1. Achetez du service aupr\303\250s de la soci\303\251t\303\251 RyX\303\251o qui porte le projet Abul\303\211du et embauche des d\303\251veloppeurs de logiciels libres. </span><a href=\"https://ryxeo.com/boutique/\"><span style=\" font-family:'Sans'; font-size:10pt; text-decoration: underline; color:#0000ff;\">https://ryxeo.com/boutique/</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans'; font-size:10pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:10pt;\">2. Faites un don \303\240 l'association abuledu-fr.org pour lui permettre de prendre en c"
                        "harge les frais de d\303\251placements des b\303\251n\303\251voles et assurer sa mission. </span><a href=\"http://abuledu-fr.org/Faire-un-don-a-l-association.html\"><span style=\" font-family:'Sans'; font-size:10pt; text-decoration: underline; color:#0000ff;\">http://abuledu-fr.org/Faire-un-don-a-l-association.html</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans'; font-size:10pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:10pt;\">3. Participez au forum d'entraide en donnant un coup de pouce \303\240 ceux qui ne savent pas encore se servir aussi bien que vous des diff\303\251rents logiciels</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; fo"
                        "nt-family:'Sans'; font-size:10pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:10pt;\">4. Traduisez ce logiciel dans d'autres langues, pour cel\303\240 proposez votre aide sur la liste dev@abuledu.org. Allez sur le site suivant pour vous y abonner: </span><a href=\"http://listes.abuledu.org/wws/info/dev\"><span style=\" font-family:'Sans'; font-size:10pt; text-decoration: underline; color:#0000ff;\">http://listes.abuledu.org/wws/info/dev</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans'; font-size:10pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:10pt;\">5. Faites nous conna\303\256tre aupr\303\250s de vos amis, contacts"
                        " et tout autour de vous, plus nous sommes nombreux et plus nos projets avanceront vite et bien.</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabTranslate), QApplication::translate("AbulEduAproposV0", "Contribuez", 0, QApplication::UnicodeUTF8));
        textAbout->setHtml(QApplication::translate("AbulEduAproposV0", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; mar"
                        "gin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans'; font-size:10pt;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\">Cr\303\251dits :</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\">O. pour m'avoir donn\303\251 l'id\303\251e</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\">de feuilleter la revue </span><span style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; font-style:italic; color:#00007f;\">Sport C\303\251r\303\251bral</span><span style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\">.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\">Et toute l'\303\251quipe d'Abul\303\211du et de Ryx\303\251o</span></p>\n"
"<p align=\"center\" style=\" margi"
                        "n-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:600; color:#00007f;\">pour leur aide, leur soutien moral.</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabAbout), QApplication::translate("AbulEduAproposV0", "\303\200 propos", 0, QApplication::UnicodeUTF8));
        pushButtonFermer->setText(QApplication::translate("AbulEduAproposV0", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AbulEduAproposV0: public Ui_AbulEduAproposV0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABULEDUAPROPOSV0_H
