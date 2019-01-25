/**
 *  OSM
 *  Copyright (C) 2018  Pavel Smokotnin

 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OUTPUTDEVICE_H
#define OUTPUTDEVICE_H

#include <QIODevice>
#include <QDebug>

#include "sample.h"

class OutputDevice : public QIODevice
{
    Q_OBJECT

protected:
    int sampleRate;
    int m_chanel, m_aux, m_chanelCount;
    float m_gain;

public:
    OutputDevice(QObject *parent);
    QString name = "Silent";

    qint64 writeData(const char *data, qint64 len);
    qint64 readData(char *data, qint64 maxlen);
    virtual Sample sample(void);

    void setSamplerate(int s) {sampleRate = s;}

public slots:
    void setGain(float gaindB);
    void setChanel(int chanel) {m_chanel = chanel;}
    void setAux(int chanel) {m_aux = chanel;}
    void setChanelCount(int count) {m_chanelCount = count;}

};

#endif // OUTPUTDEVICE_H
