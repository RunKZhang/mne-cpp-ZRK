#--------------------------------------------------------------------------------------------------------------
#
# @file     scDisp.pro
# @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
#           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
# @version  1.0
# @date     July, 2012
#
# @section  LICENSE
#
# Copyright (C) 2012, Christoph Dinh and Matti Hamalainen. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that
# the following conditions are met:
#     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
#       following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
#       the following disclaimer in the documentation and/or other materials provided with the distribution.
#     * Neither the name of MNE-CPP authors nor the names of its contributors may be used
#       to endorse or promote products derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
# PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
#
# @brief    This project file builds the scDisp library.
#
#--------------------------------------------------------------------------------------------------------------

include(../../../../mne-cpp.pri)

TEMPLATE = lib

QT += widgets concurrent xml svg 3dextras


DEFINES += SCDISP_LIBRARY

TARGET = scDisp
CONFIG(debug, debug|release) {
    TARGET = $$join(TARGET,,,d)
}

LIBS += -L$${MNE_LIBRARY_DIR}
CONFIG(debug, debug|release) {
    LIBS += -lMNE$${MNE_LIB_VERSION}Utilsd \
            -lMNE$${MNE_LIB_VERSION}Fsd \
            -lMNE$${MNE_LIB_VERSION}Fiffd \
            -lMNE$${MNE_LIB_VERSION}Mned \
            -lMNE$${MNE_LIB_VERSION}Fwdd \
            -lMNE$${MNE_LIB_VERSION}Inversed \
            -lMNE$${MNE_LIB_VERSION}Connectivityd \
            -lMNE$${MNE_LIB_VERSION}Realtimed \
            -lMNE$${MNE_LIB_VERSION}Dispd \
            -lMNE$${MNE_LIB_VERSION}Disp3Dd \
            -lscMeasd
}
else {
    LIBS += -lMNE$${MNE_LIB_VERSION}Utils \
            -lMNE$${MNE_LIB_VERSION}Fs \
            -lMNE$${MNE_LIB_VERSION}Fiff \
            -lMNE$${MNE_LIB_VERSION}Mne \
            -lMNE$${MNE_LIB_VERSION}Fwd \
            -lMNE$${MNE_LIB_VERSION}Inverse \
            -lMNE$${MNE_LIB_VERSION}Connectivity \
            -lMNE$${MNE_LIB_VERSION}Realtime \
            -lMNE$${MNE_LIB_VERSION}Disp \
            -lMNE$${MNE_LIB_VERSION}Disp3D \
            -lscMeas
}

DESTDIR = $${MNE_LIBRARY_DIR}

#
# win32: copy dll's to bin dir
# unix: add lib folder to LD_LIBRARY_PATH
#
win32 {
    FILE = $${DESTDIR}/$${TARGET}.dll
    BINDIR = $${DESTDIR}/../bin
    FILE ~= s,/,\\,g
    BINDIR ~= s,/,\\,g
    QMAKE_POST_LINK += $${QMAKE_COPY} $$quote($${FILE}) $$quote($${BINDIR}) $$escape_expand(\\n\\t)
}

SOURCES += \
    measurementwidget.cpp \
    newmeasurementwidget.cpp \
    realtimemultisamplearraywidget.cpp \
    realtimesamplearraywidget.cpp \
    realtimeevokedsetwidget.cpp \
    realtimeevokedwidget.cpp \
    realtimecovwidget.cpp \
    frequencyspectrumwidget.cpp \
    helpers/realtimebutterflyplot.cpp \
    helpers/realtimemultisamplearraymodel.cpp \
    helpers/realtimemultisamplearraydelegate.cpp \
    helpers/realtimeevokedmodel.cpp \
    helpers/realtimeevokedsetmodel.cpp \
    helpers/covmodalitywidget.cpp \
    helpers/frequencyspectrummodel.cpp \
    helpers/frequencyspectrumdelegate.cpp \
    helpers/frequencyspectrumsettingswidget.cpp \
    helpers/quickcontrolwidget.cpp \
    realtimesourceestimatewidget.cpp \
    realtimeconnectivityestimatewidget.cpp \
    hpiwidget.cpp \

HEADERS += \
    scdisp_global.h \
    measurementwidget.h \
    newmeasurementwidget.h \
    realtimemultisamplearraywidget.h \
    realtimesamplearraywidget.h \
    realtimeevokedsetwidget.h \
    realtimeevokedwidget.h \
    realtimecovwidget.h \
    frequencyspectrumwidget.h \
    helpers/realtimemultisamplearraymodel.h \
    helpers/realtimemultisamplearraydelegate.h \
    helpers/realtimeevokedmodel.h \
    helpers/realtimeevokedsetmodel.h \
    helpers/realtimebutterflyplot.h \
    helpers/covmodalitywidget.h \
    helpers/frequencyspectrumdelegate.h \
    helpers/frequencyspectrummodel.h \
    helpers/frequencyspectrumsettingswidget.h \
    helpers/quickcontrolwidget.h \
    realtimesourceestimatewidget.h \
    realtimeconnectivityestimatewidget.h \
    hpiwidget.h \

FORMS += \
    FormFiles/realtimesamplearraywidget.ui \
    helpers/quickcontrolwidget.ui \
    FormFiles/hpiwidget.ui

RESOURCES += \
    scDisp.qrc

RESOURCE_FILES +=\
    $${MNE_DIR}/resources/general/sensorSurfaces/306m.fif \
    $${MNE_DIR}/resources/general/sensorSurfaces/306m_rt.fif \
    $${MNE_DIR}/resources/general/sensorSurfaces/BabyMEG.fif \
    $${MNE_DIR}/resources/general/sensorSurfaces/BabySQUID.fif \
    $${MNE_DIR}/resources/general/sensorSurfaces/BabySQUID.fif \
    $${MNE_DIR}/resources/general/hpiAlignment/fsaverage-fiducials.fif \
    $${MNE_DIR}/resources/general/hpiAlignment/fsaverage-head.fif \
    $${MNE_DIR}/resources/general/hpiAlignment/fsaverage-inner_skull-bem.fif \
    $${MNE_DIR}/resources/general/hpiAlignment/fsaverage-trans.fif \
    $${MNE_DIR}/resources/mne_scan/plugins/noisereduction/SPHARA/BabyMEG_SPHARA_InvEuclidean_Inner.txt \
    $${MNE_DIR}/resources/mne_scan/plugins/noisereduction/SPHARA/BabyMEG_SPHARA_InvEuclidean_Outer.txt \
    $${MNE_DIR}/resources/mne_scan/plugins/noisereduction/SPHARA/Current_SPHARA_EEG.txt \
    $${MNE_DIR}/resources/mne_scan/plugins/noisereduction/SPHARA/Duke64Dry.txt \
    $${MNE_DIR}/resources/mne_scan/plugins/noisereduction/SPHARA/Vectorview_SPHARA_InvEuclidean_Grad.txt \
    $${MNE_DIR}/resources/mne_scan/plugins/noisereduction/SPHARA/Vectorview_SPHARA_InvEuclidean_Mag.txt \

# Copy resource files to bin resource folder
for(FILE, RESOURCE_FILES) {
    FILEDIR = $$dirname(FILE)
    FILEDIR ~= s,/resources,/bin/resources,g
    FILEDIR ~= s,/,\\,g
    TRGTDIR = $${FILEDIR}

    QMAKE_POST_LINK += $$sprintf($${QMAKE_MKDIR_CMD}, "$${TRGTDIR}") $$escape_expand(\n\t)

    FILE ~= s,/,\\,g
    TRGTDIR ~= s,/,\\,g
    QMAKE_POST_LINK += $${QMAKE_COPY} $$quote($${FILE}) $$quote($${TRGTDIR}) $$escape_expand(\\n\\t)
}

UI_DIR = $${PWD}

INCLUDEPATH += $${EIGEN_INCLUDE_DIR}

INCLUDEPATH += $${MNE_INCLUDE_DIR}
INCLUDEPATH += $${MNE_SCAN_INCLUDE_DIR}

# Install headers to include directory
header_files.files = ./*.h
header_files.path = $${MNE_SCAN_INCLUDE_DIR}/scDisp

INSTALLS += header_files

OTHER_FILES +=

contains(MNECPP_CONFIG, BuildBasicMNESCANVersion) {
    DEFINES += BUILD_BASIC_MNESCAN_VERSION
}

# Deploy Qt Dependencies
win32 {
    isEmpty(TARGET_EXT) {
        TARGET_CUSTOM_EXT = .dll
    } else {
        TARGET_CUSTOM_EXT = $${TARGET_EXT}
    }

    DEPLOY_COMMAND = windeployqt

    DEPLOY_TARGET = $$shell_quote($$shell_path($${MNE_BINARY_DIR}/$${TARGET}$${TARGET_CUSTOM_EXT}))

    #  # Uncomment the following line to help debug the deploy command when running qmake
    #  warning($${DEPLOY_COMMAND} $${DEPLOY_TARGET})
    QMAKE_POST_LINK += $${DEPLOY_COMMAND} $${DEPLOY_TARGET}
}
