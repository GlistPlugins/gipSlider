/*
 * gipSlider.h
 *
 *  Created on: Jun 26, 2021
 *      Author: kayra
 */

#ifndef SRC_GIPSLIDER_H_
#define SRC_GIPSLIDER_H_

#include "gFont.h"
#include "gBasePlugin.h"
#include "gImage.h"

class gipSlider : public gBasePlugin {
	typedef std::string str;

public:
	static const int LABEL_SMALL = 0, LABEL_NORMAL = 1, LABEL_BIG = 2;

	gipSlider();
	virtual ~gipSlider();

	/**
	 * @return The id that's given to the slider object
	 */
	int getID();

	void setup();
	void update();
	void draw();

	/**
	 * All-in-one function for creating a slider in a single line.
	 *
	 * Usage of this function is highly recommended unless the developer knows what
	 * he/she is doing as this function calls the helper functions in a hierarchical
	 * order.
	 *
	 * @param trackPath The fullname of the track image stored under project's images
	 * folder. Fullname should contain image name and its extension. It is case
 	 * sensitive.
	 * @param imagePath The fullname of the thumb image stored under project's images
	 * folder. Fullname should contain image name and its extension. It is case
 	 * sensitive.
 	 * @param hasLabel Whether the thumb should have label with the value on top of it.
	 * @param size The enum representation of the size. Ex: gipSlider::LABEL_SMALL
	 * @param minrange The minimum value that the thumb can display.
	 * @param maxrange The maximum value that the thumb can display.
	 * @param Slider's top left x position
	 * @param Slider's top left y position
	 * @param sx How much the slider will be scaled on the x axis from the original x
	 * position
	 * @param sy How much the slider will be scaled on the y axis from the original y
	 * position
	 */
	void set(str trackPath, str thumbPath, str fontPath, bool hasLabel = false, int size = LABEL_SMALL, int minrange = 0, int maxrange = 1, int x = 0, int y = 0, float trakcsx = 1, float tracksy = 1, float thumbx = 1, float thumbsy = 1);

	/**
	 * The track is the slider's stick that shows the range for a user to select from.
	 * The smallest value appears at the far-left of the track, while the largest
	 * value appears on the far-right.
	 *
	 * The track in the image should always be in the center of the image, and the
	 * image should not contain any blank spaces around the track.
	 *
	 * @param imagePath The fullname of the track image stored under project's images
	 * folder. Fullname should contain image name and its extension. It is case
 	 * sensitive.
	 */
	void loadTrack(str imagePath);

	/**
	 * The thumb is a position indicator that can be moved along the track, displaying
	 * the selected value of its position.
	 *
	 * The thumb in the image should always be in the center of the image, and the
	 * image should not contain any blank spaces around the thumb.
	 *
	 * @param imagePath The fullname of the thumb image stored under project's images
	 * folder. Fullname should contain image name and its extension. It is case
 	 * sensitive.
	 */
	void loadThumb(str imagePath);

	/**
	 * Loads the value label's font.
	 *
	 * @param fontPath The fullname of the font stored under project's fonts folder.
	 * Fullname should contain font name and its extension. It is case sensitive.
	 */
	void loadFont(str fontPath);

	/**
	 * A value label displays the specific numeric value that corresponds with the
	 * thumb’s placement. The value is displayed on top of the thumb
	 *
	 * @param hasLabel Whether the thumb should have label with the value on top of it.
	 */
	void hasValueLabel(bool hasLabel);

	/**
	 * Sets the font size for the label.
	 *
	 * @param size The enum representation of the size. Ex: gipSlider::LABEL_SMALL
	 */
	void setLabelSize(int size);

	/**
	 * This function sets the value range that the track represents. This value also
	 * determines the minimum and maximum value the thumb can show.
	 *
	 * @param min The minimum value that the thumb can display.
	 * @param max The maximum value that the thumb can display.
	 */
	void setRange(float min, float max);

	/**
	 * Sets the position of the slider on the canvas.
	 *
	 * @param Slider's top left x position
	 * @param Slider's top left y position
	 */
	void setPosition(int x, int y);

	/**
	 * Sets the size scale of the slider.
	 *
	 * If the slider is not scaled, the images will be in their original dimensions.
	 *
	 * This function automatically scales the thumb image to be fitting for the track.
	 * If the developer wants to scale the track and the thumb seperately, refer to:
	 * @see setScale(int, int, int, int)
	 *
	 * @param sx How much the slider will be scaled on the x axis from the original x
	 * position
	 * @param sy How much the slider will be scaled on the y axis from the original y
	 * position
	 */
	void setScale(float sx, float sy);

	/**
	 * Sets the size scale of the slider.
	 *
	 * If the slider is not scaled, the images will be in their original dimensions.
	 *
	 * @param tracksx How much the track will be scaled on the x axis from the original x
	 * position
	 * @param tracksy How much the track will be scaled on the y axis from the original y
	 * position
	 * @param thumbsx How much the thumb will be scaled on the x axis from the original x
	 * position
	 * @param thumbsy How much the thumb will be scaled on the y axis from the original y
	 * position
	 */
	void setScale(float tracksx, float tracksy, float thumbsx, float thumbsy);

	/**
	 * Get the value at the thumb's position on the track.
	 *
	 * @return Thumb's position mapped to the range, specified by the setRange function.
	 */
	float getValue();

	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

private:
	static const int labelsizenum = 3;

	gFont valuelabel;
	int labelx, labely;
	int labeloffsetx, labeloffsety;
	int labelfontsize;
	int labelsize[labelsizenum];
	bool labelactive;

	gImage track, thumb;
	int trackx, tracky, trackw, trackh;
	int thumbx, thumby, thumbw, thumbh;

	int id;
	float value;
	float minvalue, maxvalue;
	bool hasLabel;
	int mouseinitialx;
	bool dragging;

	void setLabelPos(int labelx, int labely);

	static int generateID();
	static int nextSliderID;
};

#endif /* SRC_GIPSLIDER_H_ */
