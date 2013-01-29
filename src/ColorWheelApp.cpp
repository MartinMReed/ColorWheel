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

#include "ColorWheelApp.h"

#include <bb/cascades/QmlDocument>
#include <bb/cascades/Application>
#include <bb/cascades/Container>
#include <bb/cascades/Page>

#include <screen/screen.h>

#include "ColorPickerView.h"
#include "ColorWheelView.h"
#include "BrightnessBarView.h"

using namespace bb::cascades;

ColorWheelApp::ColorWheelApp()
{
    qmlRegisterType<ColorPickerView>("hardisonbrewing", 1, 0, "ColorPickerView");
    qmlRegisterType<ColorWheelView>("hardisonbrewing", 1, 0, "ColorWheelView");
    qmlRegisterType<BrightnessBarView>("hardisonbrewing", 1, 0, "BrightnessBarView");

    QmlDocument *qml = QmlDocument::create("asset:///main.qml");

    if (qml->hasErrors())
    {
        exit(-1);
        return;
    }

    Page* page = qml->createRootObject<Page>();
    Application::instance()->setScene(page);
}

ColorWheelApp::~ColorWheelApp()
{
}
