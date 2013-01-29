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

#include "BrightnessBarView.h"

#include "ColorPickerView.h"

#include <bb/cascades/AbsoluteLayoutProperties>
#include <bb/cascades/Container>
#include <bb/cascades/Color>
#include <bb/cascades/AbsoluteLayout>

#include <time.h>

using namespace bb::cascades;

BrightnessBarView::BrightnessBarView(Container* parent)
        : Container(parent)
{
    selectorImageView = 0;

    QObject::connect(this, SIGNAL(creationCompleted()),
            this, SLOT(onCreationCompleted(void)));

    QObject::connect(this, SIGNAL(touch(bb::cascades::TouchEvent*)),
            this, SLOT(onTouch(bb::cascades::TouchEvent*)));
}

BrightnessBarView::~BrightnessBarView()
{
}

void BrightnessBarView::onCreationCompleted()
{
    colorPickerView = (ColorPickerView*) parent()->parent();
    selectorImageView = findChild<ImageView*>("selectorImageView");
    barImageView = findChild<ImageView*>("barImageView");

    fillSelectorSquare();
    fillBrightnessBar();

    srand(time(0));

    int randX = rand() % (int) barImageView->preferredWidth();

    AbsoluteLayoutProperties* wheelLayout =
            dynamic_cast<AbsoluteLayoutProperties*>(barImageView->layoutProperties());

    randX += wheelLayout->positionX();

    selectBrightness(randX);
}

void BrightnessBarView::onTouch(bb::cascades::TouchEvent* touchEvent)
{
    float x = touchEvent->localX();

    AbsoluteLayoutProperties* barLayout =
            dynamic_cast<AbsoluteLayoutProperties*>(barImageView->layoutProperties());

    float positionX = barLayout->positionX();
    float width = barImageView->preferredWidth();

    if (x < positionX || x >= positionX + width)
    {
        return;
    }

    selectBrightness(x);
}

void BrightnessBarView::fillBrightnessBar()
{
    float width = preferredWidth();
    float height = preferredHeight();

    barImageData = bb::ImageData(bb::PixelFormat::RGBA_Premultiplied, width, height);
    int stride = barImageData.bytesPerLine();
    unsigned char* pixels = barImageData.pixels();
    bzero(pixels, sizeof(unsigned char) * stride * height);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float v = 255 - (((x + 1) / width) * 255);

            int p = (y * stride) + (x * 4);
            pixels[p + 0] = v;
            pixels[p + 1] = v;
            pixels[p + 2] = v;
            pixels[p + 3] = 255;
        }
    }

    barImageView->setImage(Image(barImageData));
}

void BrightnessBarView::fillSelectorSquare()
{
    float width = selectorImageView->preferredWidth() - 1;
    float height = selectorImageView->preferredHeight() - 1;
    int radius = (int) fmin(width / 2, height / 2);

    bb::ImageData imageData = bb::ImageData(bb::PixelFormat::RGBA_Premultiplied, width, height);
    int stride = imageData.bytesPerLine();
    unsigned char* pixels = imageData.pixels();
    bzero(pixels, sizeof(unsigned char) * stride * height);

    for (int radi = radius; radi >= radius - 7; radi--)
    {
        for (float radian = 0; radian < 2 * M_PI; radian += .001)
        {
            int x = radius + round(radi * cos(radian));
            int y = radius + round(radi * sin(radian));

            int p = (y * stride) + (x * 4);
            pixels[p + 0] = 255;
            pixels[p + 1] = 0;
            pixels[p + 2] = 0;
            pixels[p + 3] = 255;
        }
    }

    selectorImageView->setImage(Image(imageData));
}

void BrightnessBarView::selectBrightness(float x)
{
    AbsoluteLayoutProperties* selectorLayout =
            dynamic_cast<AbsoluteLayoutProperties*>(selectorImageView->layoutProperties());

    AbsoluteLayoutProperties* barlayout =
            dynamic_cast<AbsoluteLayoutProperties*>(barImageView->layoutProperties());

    float imageViewWidth = barImageView->preferredWidth();
    float imageViewX = barlayout->positionX();

    float selectorWidth = selectorImageView->preferredWidth();
    float selectorX = x - (0.50 * selectorWidth);
    selectorX = fmax(imageViewX + 1, fmin(selectorX, (imageViewX + imageViewWidth) - (selectorWidth + 1)));

    selectorLayout->setPositionX(selectorX);
    selectorLayout->setPositionY(0.50 * (preferredHeight() - selectorImageView->preferredHeight()));

    x -= barlayout->positionX();

    const unsigned char* pixels = barImageData.constPixels();

    int p = x * 4;
    int v = pixels[p];

    colorPickerView->setColor(v);
}
