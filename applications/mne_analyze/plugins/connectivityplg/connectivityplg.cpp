//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "connectivityplg.h"

#include <anShared/Management/analyzedata.h>
#include <anShared/Management/communicator.h>
#include <anShared/Utils/metatypes.h>
#include <disp/viewers/connectivitysettingsview.h>

#include <disp3D/viewers/networkview.h>
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace ANSHAREDLIB;
using namespace CONNECTIVITYPLGPLUGIN;
using namespace DISPLIB;
using namespace DISP3DLIB;

Connectivityplg::Connectivityplg()
: m_pConnectivitySettingsView(Q_NULLPTR)
{
}

//=============================================================================================================

Connectivityplg::~Connectivityplg()
{
}

QSharedPointer<AbstractPlugin> Connectivityplg::clone() const
{
    QSharedPointer<Connectivityplg> pConnectivityplgClone = QSharedPointer<Connectivityplg>::create();
    return pConnectivityplgClone;
}

void Connectivityplg::init()
{
    m_pCommu = new Communicator(this);
}


void Connectivityplg::unload()
{
}

//=============================================================================================================

QString Connectivityplg::getName() const
{
    return "Connectivityplg";
}

//=============================================================================================================

QMenu *Connectivityplg::getMenu()
{
    return Q_NULLPTR;
}

QDockWidget *Connectivityplg::getControl()
{

    //If plugin has dock controls:

    m_pConnectivitySettingsView = new DISPLIB::ConnectivitySettingsView("MNEANALYZE");


    //QWidget* pWidget = new QWidget;
    //QVBoxLayout* pLayout = new QVBoxLayout;

    //pWidget->setLayout(pLayout);


    QDockWidget* pControlDock = new QDockWidget(getName());
    pControlDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    pControlDock->setWidget(m_pConnectivitySettingsView);
    pControlDock->setObjectName(getName());


    return pControlDock;

    //If plugin does not have dock controls:
    //return Q_NULLPTR;
}

QWidget *Connectivityplg::getView()
{

    //If the plugin has a view:
    //m_pNetworkView = new DISP3DLIB::NetworkView();
    //QWidget* pNetworkViewWidget = new QWidget();
    //QVBoxLayout* pViewLayout = new QVBoxLayout();


    //pNetworkViewWidget->setLayout(m_pNetworkView);

    //return pNetworkViewWidget;

    //If the plugin does not have a view:
    return Q_NULLPTR;
}

void Connectivityplg::handleEvent(QSharedPointer<Event> e)
{
    switch (e->getType()) {
    default:
        qWarning() << "[SamplePlugin::handleEvent] received an Event that is not handled by switch-cases";
        break;
    }
}

//=============================================================================================================

QVector<EVENT_TYPE> Connectivityplg::getEventSubscriptions(void) const
{
    QVector<EVENT_TYPE> temp;
    temp.push_back(SELECTED_MODEL_CHANGED);
    return temp;
}
//=============================================================================================================
QString Connectivityplg::getBuildInfo()
{
    return QString(CONNECTIVITYPLGPLUGIN::buildDateTime()) + QString(" - ")  + QString(CONNECTIVITYPLGPLUGIN::buildHash());
}
//=============================================================================================================
void Connectivityplg::onconnectivityMetricChanged()
{}
