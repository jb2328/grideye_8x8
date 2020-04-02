### Processing README.md
#### Color palette
`Processing/rgb_lerp` has RGB color codes to be pasted in Arduino/RPi/Feather/Lopy code to create a color pallete for the LED matrix.
The code is using linear interpolation between colors to create smooth transitions. The interpolation is done in HSB color space to have a broader range of colors and then is converted to RGB values and in the end we get the following output:

`...matrix.Color( 12 , 92 , 89 ),
 matrix.Color( 12 , 92 , 83 ),
 matrix.Color( 12 , 93 , 78 )...`

Then it can be pasted into the code as an array for the aforementioned devices.

**The entire generated 64 entry color palette converted to RGB colors can be found in [palette.py](https://github.com/jb2328/grideye_8x8/blob/master/Processing/palette.py).**

#### Entire color scheme:
HSB:

![HSB_palette](https://github.com/jb2328/grideye_8x8/blob/master/images/color_scheme.png?raw=true "HSB_color_scheme")

RGB:

![RGB_palette](https://github.com/jb2328/grideye_8x8/blob/master/images/color_scheme_RGB.png?raw=true "RGB_color_scheme")

Linear interpolation done in RGB color space is problematic here as it does not iterate through the entire color space, it only does the interpolation from red to green to blue, ultimately ending up with a muddy and limited color palette that is not very suitable for the DotStar matrix.

[More about Processing](https://processing.org/)

##### HSB linear interpolation
define color mode

`colorMode(HSB, 100);` 

//declare start/end colors

BLUE `color from = color(70, 80, 90);`

RED `color to = color(100, 100, 100);`

interpolate over 64 step

`lerpColors(from, to, 64);`

Then gets reconverted to RGB and exported since DotStar doesn't support HSB natively.

##### RGB linear interpolation
define color mode

`colorMode(RGB);`

declare start/middle/end colors

RED `color from = color(255, 0, 0);` 

GREEN `color to = color(0, 255, 0);`   
 
GREEN `color from2 = color(0, 255, 0);`

BLUE `color to2 = color(0, 0, 255); `

interpolate over 32 steps

`lerpColors(from, to, 32);`

interpolate over 32 steps again

`lerpColors(from2, to2, 32);`

Export RGB values.