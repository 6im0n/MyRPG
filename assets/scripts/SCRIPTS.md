# FILE CONFIGURATION

## Position

set a position in x and y
`position: x y`
you can also define position from pourcentage with a point just before the number, example :
`position: .50 250`
x take 50% of the widht windows.

## Size

Set a size with x and y
`size: x y`
you can also define position from pourcentage with a point just before the number

Example :
`size: .10 250`
x take 10% of the widht windows and y take 250 pixels.

## Rect

Set a Rect with left, top, widht and height
`rect: left top widht height`

Example:
`rect: 163 210 90 27`

## Style

Set Style of the component.
It refer to the structure `component_styles` and take the enum of the texture, sound and font.
`style : texture sound font`

Example:
`style: 4 1 0`

## Type

Set Type of the component.
It refer to the structure `component_type_t`and take the enum of the type.
`type : type`

Example:
`type: 2`

## C\_size

Set c\_size of the component.
It refer to the structure `component_size_t`and take the enum of the type.
`c_size : c_size`

Example:
`c_size: 2`

## Functions

### Clicked

Set function clicked of the component
It refer to the structure `clicked_t`and take the enum of the type.
`clicked : function`

Example:
`clicked: 0`

### Hover

Set function hover of the component
It refer to the structure `hover_t`and take the enum of the type.
`disabled : function`

Example:
`disanled: 0`

### Disabled

Set function disabled of the component
It refer to the structure `disabled`and take the enum of the type.
`disabled : function`

Example:
`disanled: 0`