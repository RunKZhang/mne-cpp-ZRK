//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "connectivityplg.h"

#include <anShared/Management/analyzedata.h>
#include <anShared/Management/communicator.h>
#include <anShared/Utils/metatypes.h>


//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace ANSHAREDLIB;
using namespace CONNECTIVITYPLGPLUGIN;

Connectivityplg::Connectivityplg()
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
    QDockWidget* pControlDock = new QDockWidget(getName());
    pControlDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    pControlDock->setObjectName(getName());

    QWidget* pWidget = new QWidget;
    QVBoxLayout* pLayout = new QVBoxLayout;

    pWidget->setLayout(pLayout);
    pControlDock->setWidget(pWidget);

    return pControlDock;

    //If plugin does not have dock controls:
    //return Q_NULLPTR;
}

QWidget *Connectivityplg::getView()
{
    /*
    //If the plugin has a view:
    QWidget* pPluginView = new QWidget();
    QVBoxLayout* pViewLayout = new QVBoxLayout();

    pPluginView->setLayout(pViewLayout);

    return pPluginView;
*/
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

    return temp;
}
