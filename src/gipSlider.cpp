/*
 * gipSlider.cpp
 *
 *  Created on: Jun 26, 2021
 *      Author: kayra
 */

#include "gipSlider.h"

int gipSlider::nextSliderID = 1;

gipSlider::gipSlider() {
	id = generateID();
	setup();
}

gipSlider::~gipSlider() {
}

int gipSlider::generateID() {
	return (nextSliderID++) - 1;
}

int gipSlider::getID() {
	return id;
}

void gipSlider::setup() {
	labelsize[LABEL_SMALL] = 10;
	labelsize[LABEL_NORMAL] = 15;
	labelsize[LABEL_BIG] = 20;
	setLabelSize(LABEL_SMALL);
	minvalue = 0;
	maxvalue = 1;
	value = maxvalue;
	hasLabel = false;
	labelactive = false;
	labeloffsetx = 2;
	labeloffsety = 2;
}

void gipSlider::update() {
}

void gipSlider::draw() {
	track.draw(trackx, tracky, trackw, trackh);
	thumb.draw(thumbx, thumby, thumbw, thumbh);
	if(hasLabel && labelactive) valuelabel.drawText(gToStr(value), labelx, labely);
}

void gipSlider::set(str trackPath, str thumbPath, str fontPath, bool hasLabel, int size, int minrange, int maxrange, int x, int y, float tracksx, float tracksy, float thumbsx, float thumbsy) {
	loadTrack(trackPath);
	loadThumb(thumbPath);
	hasValueLabel(hasLabel);
	setLabelSize(size);
	loadFont(fontPath);
	setRange(minrange, maxrange);
	setPosition(x, y);
	setScale(tracksx, tracksy, thumbsx, thumbsy);
}

void gipSlider::loadTrack(str imagePath) {
	track.loadImage(imagePath);
	trackw = track.getWidth();
	trackh = track.getHeight();
}

void gipSlider::loadThumb(str imagePath) {
	thumb.loadImage(imagePath);
	thumbw = thumb.getWidth();
	thumbh = thumb.getWidth();
}

void gipSlider::loadFont(str fontPath) {
	valuelabel.loadFont(fontPath, labelfontsize);
}

void gipSlider::hasValueLabel(bool hasLabel) {
	this->hasLabel = hasLabel;
}

void gipSlider::setLabelSize(int size) {
	labelfontsize = labelsize[size];
}

void gipSlider::setRange(float min, float max) {
	minvalue = min;
	maxvalue = max;

	value = maxvalue;
}

void gipSlider::setPosition(int x, int y) {
	trackx = x;
	tracky = y;

	thumbx = trackx + trackw - (thumbw / 2);
	thumby = tracky + (trackh / 2) - (thumbh / 2);

	if(hasLabel) {
		labelx = thumbx + (thumbw / 2) - (valuelabel.getStringWidth(gToStr(value)) / 2) - labeloffsetx;
		labely = thumby - valuelabel.getStringHeight(gToStr(value)) - labeloffsety;
	}
}

void gipSlider::setScale(float sx, float sy) {
	trackw = trackw * sx;
	trackh = trackh * sy;
	thumbw = trackw / 8;
	thumbh = trackh * 2;

	setPosition(trackx, tracky); // recalculate the thumb's position
}

void gipSlider::setScale(float tracksx, float tracksy, float thumbsx, float thumbsy) {
	trackw = trackw * tracksx;
	trackh = trackh * tracksy;
	thumbw = thumbw * thumbsx;
	thumbh = thumbh * thumbsy;

	setPosition(trackx, tracky); // recalculate the the thumb's position
}

void gipSlider::mouseDragged(int x, int y, int button) {
	if(dragging) {
		thumbx += (x - mouseinitialx);
		if (thumbx < trackx - (thumbw / 2)) {
			thumbx = trackx - (thumbw / 2);
		} else if (thumbx > trackx + trackw - (thumbw / 2)) {
			thumbx = trackx + trackw - (thumbw / 2);
		}
		value = (((thumbx + (thumbw / 2) - trackx) * (maxvalue - minvalue)) / trackw) + minvalue;
		if(hasLabel && labelactive) {
			if(value < 0) labeloffsetx = 4;
			labelx = thumbx + (thumbw / 2) - (valuelabel.getStringWidth(gToStr(value)) / 2) - labeloffsetx;
		}
		mouseinitialx = thumbx + (thumbw / 2);
	}
}

void gipSlider::mousePressed(int x, int y, int button) {
	if(x >= thumbx && x < thumbx + thumbw && y >= thumby && y < thumby + thumbh) {
		dragging = true;
		labelactive = true;
		mouseinitialx = x;
	}
}

void gipSlider::mouseReleased(int x, int y, int button) {
	dragging = false;
	labelactive = false;
}
