//=============================================================================================================
/**
* @file     networkedge.cpp
* @author   Lorenz Esch <Lorenz.Esch@tu-ilmenau.de>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     August, 2016
*
* @section  LICENSE
*
* Copyright (C) 2016, Lorenz Esch and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of MNE-CPP authors nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    NetworkEdge class definition.
*
*/


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "networkedge.h"

#include "networknode.h"


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QDebug>


//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace CONNECTIVITYLIB;
using namespace Eigen;


//*************************************************************************************************************
//=============================================================================================================
// DEFINE GLOBAL METHODS
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

NetworkEdge::NetworkEdge(int iStartNodeID,
                         int iEndNodeID,
                         MatrixXd& matWeight)
: m_iStartNodeID(iStartNodeID)
, m_iEndNodeID(iEndNodeID)
{
    if(matWeight.rows() == 0 || matWeight.cols() == 0) {
        m_matWeight = MatrixXd::Zero(1,1);
        qDebug() << "NetworkEdge::NetworkEdge - Matrix weights number of rows and/or columns are zero. Setting to 1x1 zero matrix.";
    } else {
        m_matWeight = matWeight;
    }
}


//*************************************************************************************************************

int NetworkEdge::getStartNodeID()
{
    return m_iStartNodeID;
}


//*************************************************************************************************************

int NetworkEdge::getEndNodeID()
{
    return m_iEndNodeID;
}


//*************************************************************************************************************

double NetworkEdge::getWeight(int startBin, int endBin) const
{
    if(endBin < startBin || startBin < -1 || endBin < -1 ) {
        qDebug() << "Network::generateConnectMat - end bin index is larger than start bin index or one of them is negative. Returning zero matrix.";
        return 0.0;
    }

    int rows = m_matWeight.rows();
    int cols = m_matWeight.cols();
    double dWeight = 0.0;

    if(endBin-startBin+1 < cols
       && startBin < cols) {
        qDebug() << "spanning";
        dWeight = m_matWeight.block(0,startBin,rows,endBin-startBin+1).mean();
    } else if (endBin == -1
               && startBin == -1) {
        dWeight = m_matWeight.mean();
    }

    return dWeight;
}



