import bb.cascades 1.0
import hardisonbrewing 1.0

Page {
    ColorPickerView {
        id: colorPickerView
        objectName: "colorPickerView"
        layout: StackLayout {
        }
        preferredWidth: 768
        preferredHeight: 1280
        Container {
            layout: StackLayout {
            }
            layoutProperties: StackLayoutProperties {
                spaceQuota: 2
            }
            preferredHeight: colorWheelView.layoutProperties.positionY
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
            }
            Label {
                id: rgbLabel
                objectName: "rgbLabel"
                textStyle {
                    color: Color.White
                    fontSize: FontSize.XLarge
                    fontWeight: FontWeight.Bold
                    textAlign: TextAlign.Center
                }
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                preferredWidth: colorPickerView.preferredWidth
            }
            Label {
                id: hexLabel
                objectName: "hexLabel"
                textStyle {
                    color: Color.White
                    fontSize: FontSize.XLarge
                    fontWeight: FontWeight.Bold
                    textAlign: TextAlign.Center
                }
                layoutProperties: rgbLabel.layoutProperties
                preferredWidth: rgbLabel.preferredWidth
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
            }
        }
        ColorWheelView {
            id: colorWheelView
            objectName: "colorWheelView"
            layout: AbsoluteLayout {
            }
            layoutProperties: StackLayoutProperties {
                spaceQuota: 6
            }
            preferredWidth: Math.min(colorPickerView.preferredWidth, colorPickerView.preferredHeight)
            preferredHeight: preferredWidth
            ImageView {
                objectName: "wheelImageView"
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 25
                    positionY: 25
                }
                preferredWidth: colorWheelView.preferredWidth - (2 * layoutProperties.positionX)
                preferredHeight: colorWheelView.preferredHeight - (2 * layoutProperties.positionY)
            }
            ImageView {
                objectName: "selectorImageView"
                layoutProperties: AbsoluteLayoutProperties {
                }
                preferredWidth: 40
                preferredHeight: 40
            }
        }
        Container {
            layout: StackLayout {
            }
            layoutProperties: StackLayoutProperties {
                spaceQuota: 2
            }
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
            }
            BrightnessBarView {
                id: colorBarView
                objectName: "colorBarView"
                layout: AbsoluteLayout {
                }
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 3
                }
                preferredWidth: colorPickerView.preferredWidth
                preferredHeight: 100
                ImageView {
                    objectName: "barImageView"
                    layoutProperties: AbsoluteLayoutProperties {
                        positionX: 50
                    }
                    preferredWidth: colorBarView.preferredWidth - (2 * layoutProperties.positionX)
                    preferredHeight: colorBarView.preferredHeight - (2 * layoutProperties.positionY)
                }
                ImageView {
                    objectName: "selectorImageView"
                    layoutProperties: AbsoluteLayoutProperties {
                    }
                    preferredWidth: 40
                    preferredHeight: 40
                }
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
            }
        }
    }
}
