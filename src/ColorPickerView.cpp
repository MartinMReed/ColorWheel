/* Copyright (c) 2013 Martin M Reed
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ColorPickerView.h"

#include "ColorWheelView.h"

using namespace bb::cascades;

ColorPickerView::ColorPickerView(Container * parent)
        : Container(parent)
{
    rgbLabel = 0;
    hexLabel = 0;
    colorWheelView = 0;
    h = s = v = 0;
    creationComplete = false;

    QObject::connect(this, SIGNAL(creationCompleted()),
            this, SLOT(onCreationCompleted(void)));
}

ColorPickerView::~ColorPickerView()
{
    delete colorWheelView;
}

void ColorPickerView::onCreationCompleted()
{
    colorWheelView = findChild<ColorWheelView*>("colorWheelView");
    rgbLabel = findChild<Label*>("rgbLabel");
    hexLabel = findChild<Label*>("hexLabel");

    creationComplete = true;

    setColor(h, s, v);
}

void ColorPickerView::setColor(float v)
{
    this->v = v;
    setColor(h, s, v);
}

void ColorPickerView::setColor(float h, float s)
{
    this->h = h;
    this->s = s;
    setColor(h, s, v);
}

void ColorPickerView::setColor(float h, float s, float v)
{
    if (!creationComplete) return;

    int r, g, b;
    hsvToRgb(h, s, v, &r, &g, &b);

    setBackground(Color::fromARGB(qRgba(r, g, b, 255)));

    QString rgbStr = QString("rgb(%1,%2,%3)").arg(r).arg(g).arg(b);
    rgbLabel->setText(rgbStr);

    QString hexStr;
    hexStr.setNum(qRgba(r, g, b, 255), 16);
    hexLabel->setText("#" + hexStr.toUpper());

    float _r = 0.30 * (255 - r);
    float _g = 0.59 * (255 - g);
    float _b = 0.11 * (255 - b);
    Color fontColor = Color::fromARGB(qRgba(_r, _g, _b, 255));

    rgbLabel->textStyle()->setColor(fontColor);
    hexLabel->textStyle()->setColor(fontColor);
}

void ColorPickerView::hsvToRgb(float h, float s, float v, int *r, int *g, int *b)
{
    if (s == 0)
    {
        // achromatic (grey)
        *r = *g = *b = v;
        return;
    }

    h /= 60; // sector 0 to 5

    int i = floor(h);
    float f = h - i; // factorial part of h
    float p = v * (1 - s);
    float q = v * (1 - s * f);
    float t = v * (1 - s * (1 - f));

    switch (i)
    {
        case 0:
            *r = v, *g = t, *b = p;
            break;
        case 1:
            *r = q, *g = v, *b = p;
            break;
        case 2:
            *r = p, *g = v, *b = t;
            break;
        case 3:
            *r = p, *g = q, *b = v;
            break;
        case 4:
            *r = t, *g = p, *b = v;
            break;
        default:
            *r = v, *g = p, *b = q;
            break;
    }
}
