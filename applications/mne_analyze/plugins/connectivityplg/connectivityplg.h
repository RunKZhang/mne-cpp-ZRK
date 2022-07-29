#ifndef CONNECTIVITYPLG_H
#define CONNECTIVITYPLG_H

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "connectivityplg_global.h"

#include <anShared/Plugins/abstractplugin.h>

//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QtWidgets>
#include <QtCore/QtPlugin>
#include <QDebug>
#include <QPointer>

//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================

namespace ANSHAREDLIB {
    class Communicator;
}

/*
namespace RTPROCESSINGLIB {
    class FilterKernel;
}
*/
/*
namespace DISPLIB {
    class FilterSettingsView;
}
*/
//=============================================================================================================
// DEFINE NAMESPACE SURFERPLUGIN
//=============================================================================================================

namespace CONNECTIVITYPLGPLUGIN
{

//=============================================================================================================
/**
 * Filtering Plugin
 *
 * @brief The Filtering class provides a view with all currently loaded models.
 */
class CONNECTIVITYPLGSHARED_EXPORT Connectivityplg : public ANSHAREDLIB::AbstractPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ansharedlib/1.0" FILE "connectivityplg.json") //New Qt5 Plugin system replaces Q_EXPORT_PLUGIN2 macro
    // Use the Q_INTERFACES() macro to tell Qt's meta-object system about the interfaces
    Q_INTERFACES(ANSHAREDLIB::AbstractPlugin)

public:
    //=========================================================================================================
    /**
     * Constructs a Filtering.
     */
    Connectivityplg();

    //=========================================================================================================
    /**
     * Destroys the Filtering.
     */
    virtual ~Connectivityplg() override;

    // AbstractPlugin functions
    virtual QSharedPointer<AbstractPlugin> clone() const override;
    virtual void init() override;
    virtual void unload() override;
    virtual QString getName() const override;
    virtual QMenu* getMenu() override;
    virtual QDockWidget* getControl() override;
    virtual QWidget* getView() override;
    virtual QString getBuildInfo() override;
    virtual void handleEvent(QSharedPointer<ANSHAREDLIB::Event> e) override;
    virtual QVector<ANSHAREDLIB::EVENT_TYPE> getEventSubscriptions() const override;

private:
    //=========================================================================================================
    /**
     * Sets the type of channel which are to be filtered
     *
     * @param[in] sType    The channel type which is to be filtered (EEG, MEG, All).
     */
    //void setFilterChannelType(const QString& sType);

    //=========================================================================================================
    /**
     * Filter parameters changed
     *
     * @param[in] filterData    The currently active filter.
     */
    //void setFilter(const RTPROCESSINGLIB::FilterKernel& filterData);

    //=========================================================================================================
    /**
     * Filter avtivated
     *
     * @param[in] state    The filter on/off flag.
     */
    //void setFilterActive(bool state);

    QPointer<ANSHAREDLIB::Communicator>         m_pCommu;               /**< To broadcst signals. */
    //QPointer<DISPLIB::FilterSettingsView>       m_pFilterSettingsView;

};

//=============================================================================================================
// INLINE DEFINITIONS
//=============================================================================================================

} // NAMESPACE

#endif // CONNECTIVITYPLG_H
