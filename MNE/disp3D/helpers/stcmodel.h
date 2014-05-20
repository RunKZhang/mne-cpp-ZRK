#ifndef STCMODEL_H
#define STCMODEL_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "../disp3D_global.h"

#include "stcworker.h"


//*************************************************************************************************************
//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QAbstractTableModel>
#include <QThread>


//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include <Eigen/Core>


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================

namespace MNELIB
{
    class MNESourceEstimate;
}


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace Eigen;
using namespace MNELIB;


class DISP3DSHARED_EXPORT StcModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    StcModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void addData(const MNESourceEstimate &stc);

    void setVertices(const VectorXi &vertnos);

signals:



private:
    QSharedPointer<QThread>    m_pThread;
    StcWorker::SPtr  m_pWorker;


    bool m_bRTMode;


    QVector<VectorXd> m_data;   /**< List that holds the fiff matrix data <n_channels x n_samples> */

    VectorXi m_vertices;

    qint32 m_iDownsampling;     /**< Down sampling factor */
    qint32 m_iCurrentSample;    /**< Downsampling */

};

Q_DECLARE_METATYPE(Eigen::MatrixXd);

#endif // STCMODEL_H
