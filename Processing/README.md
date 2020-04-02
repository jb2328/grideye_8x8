### Processing README.md
#### Color palette
`Processing/rgb_lerp` has RGB color codes to be pasted in Arduino/RPi/Feather/Lopy code to create a color pallete for the LED matrix.
The code is using linear interpolation between colors to create smooth transitions. The interpolation is done in HSB color space to have a broader range of colors and then is converted to RGB values and in the end we get the following output:

`...matrix.Color( 12 , 92 , 89 ),
 matrix.Color( 12 , 92 , 83 ),
 matrix.Color( 12 , 93 , 78 )...`

Then it can be pasted into the code as an array for the aforementioned devices.

#### Entire color scheme:
![palette](images/color_scheme.png "color_scheme")
![palette](images/color_scheme_RGB.png "color_scheme")

[More about Processing](https://processing.org/)
