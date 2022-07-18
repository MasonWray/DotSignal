/*
 Name:		ATM0.ino
 Created:	7/13/2022 7:24:08 PM
 Author:	Mason Wray
*/

#define DEFAULT_BRIGHTNESS 10

#include <Adafruit_DotStar.h>
Adafruit_DotStar ds(1, 7, 8, DOTSTAR_BGR);
uint8_t brightness = DEFAULT_BRIGHTNESS;

// Define Colors
const uint32_t white = ds.gamma32(ds.Color(255, 255, 255));
const uint32_t red = ds.gamma32(ds.Color(255, 0, 0));
const uint32_t green = ds.gamma32(ds.Color(0, 255, 0));
const uint32_t blue = ds.gamma32(ds.Color(0, 0, 255));
const uint32_t cyan = ds.gamma32(ds.Color(0, 255, 255));
const uint32_t magenta = ds.gamma32(ds.Color(255, 0, 255));
const uint32_t yellow = ds.gamma32(ds.Color(255, 255, 0));

//Define Brightness Levels
const uint8_t b0 = (255 / 10) * 0;
const uint8_t b1 = (255 / 10) * 1;
const uint8_t b2 = (255 / 10) * 2;
const uint8_t b3 = (255 / 10) * 3;
const uint8_t b4 = (255 / 10) * 4;
const uint8_t b5 = (255 / 10) * 5;
const uint8_t b6 = (255 / 10) * 6;
const uint8_t b7 = (255 / 10) * 7;
const uint8_t b8 = (255 / 10) * 8;
const uint8_t b9 = (255 / 10) * 9;

char c;

void setup()
{
	ds.begin();
	ds.setPixelColor(0, white);
	ds.setBrightness(brightness);
	ds.show();

	Serial.begin(9600);
	bool up = true;
	while (!Serial)
	{
		if (brightness == 0) { up = true; }
		if (brightness >= DEFAULT_BRIGHTNESS) { up = false; }
		brightness = up ? brightness + 1 : brightness - 1;
		ds.setBrightness(brightness);
		ds.show();
	}
	brightness = DEFAULT_BRIGHTNESS;
	ds.setBrightness(brightness);
	ds.show();
}

void loop()
{
	while (Serial.available())
	{
		c = Serial.read();
		parseB();
		parseC();
	}
}

void parseB()
{
	// Parse Brightness Commands
	switch (c)
	{
	case '0':
		ds.setBrightness(b0);
		ds.show();
		break;
	case '1':
		ds.setBrightness(b1);
		ds.show();
		break;
	case '2':
		ds.setBrightness(b2);
		ds.show();
		break;
	case '3':
		ds.setBrightness(b3);
		ds.show();
		break;
	case '4':
		ds.setBrightness(b4);
		ds.show();
		break;
	case '5':
		ds.setBrightness(b5);
		ds.show();
		break;
	case '6':
		ds.setBrightness(b6);
		ds.show();
		break;
	case '7':
		ds.setBrightness(b7);
		ds.show();
		break;
	case '8':
		ds.setBrightness(b8);
		ds.show();
		break;
	case '9':
		ds.setBrightness(b9);
		ds.show();
		break;
	}
}

void parseC()
{
	switch (c)
	{
	case 'w':
		ds.setPixelColor(0, white);
		ds.show();
		break;
	case 'r':
		ds.setPixelColor(0, red);
		ds.show();
		break;
	case 'g':
		ds.setPixelColor(0, green);
		ds.show();
		break;
	case 'b':
		ds.setPixelColor(0, blue);
		ds.show();
		break;
	case 'c':
		ds.setPixelColor(0, cyan);
		ds.show();
		break;
	case 'm':
		ds.setPixelColor(0, magenta);
		ds.show();
		break;
	case 'y':
		ds.setPixelColor(0, yellow);
		ds.show();
		break;
	}
}