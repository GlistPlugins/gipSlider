# gipSlider 
This GlistEngine plugin draws a slider on the screen at the given coordinates and with the images provided.
## Installation
Fork & clone this project into ~/dev/glist/glistplugins
## Usage
1.  Add gipSliderinto plugins of your `GlistApp/CMakeLists.txt`

	**` set(PLUGINS gipSlider)`**
2. Include `gipSlider.h` in your `GameCanvas.h`

	**`#include "gipSlider.h"`**
3. Define the gipSlider object in your `GameCanvas.h`

	**`gipSlider`**`slider`
4. Simply set it up in a line as shown in the example folder.
5. Get the value with the getValue() function and use it in your code.

## License
MIT
