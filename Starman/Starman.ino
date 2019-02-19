#include "U8glib.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NO_ACK);	// Display which does not send ACK

int frame = 0;

const uint8_t frame1[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x1F, 0xF0, 0x00, 0x00, 0x02, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x60, 0x0C, 0x00, 0x00, 0x02, 0x23, 0x01, 0xFF, 0xFF, 0xFF, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x02, 0x01, 0x80, 0x02, 0x43, 0x02, 0x00, 0x00, 0x00, 0x30,
0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x02, 0x80, 0x02, 0x81, 0x02, 0x00, 0x00, 0x00, 0x08,
0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x84, 0x80, 0x02, 0x81, 0x04, 0x7F, 0xFF, 0xFF, 0x88,
0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x79, 0x00, 0x03, 0x01, 0x04, 0xC0, 0x08, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3E, 0x03, 0x04, 0x80, 0x0C, 0x71, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x10, 0x03, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x04, 0x80, 0x0F, 0xFF, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x10, 0x23, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x80, 0x08, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x10, 0x30, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x01, 0xE0, 0x3B, 0x60, 0x00, 0x00, 0xF2, 0x8E, 0x04, 0x80, 0x0C, 0x71, 0xC8,
0x00, 0x00, 0x00, 0x0E, 0x00, 0x33, 0x60, 0x00, 0x0F, 0x02, 0x7E, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x10, 0x00, 0x23, 0x60, 0x00, 0xF0, 0x02, 0x1E, 0x04, 0x98, 0x4F, 0xFF, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x02, 0x1E, 0x04, 0x96, 0x88, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x1E, 0x04, 0x91, 0x0F, 0xE0, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x1E, 0x04, 0x90, 0x88, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x02, 0x1E, 0x04, 0x90, 0x4F, 0xFF, 0xC8,
0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x02, 0x1E, 0x04, 0x90, 0x40, 0x00, 0x48,
0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x02, 0x7E, 0x04, 0x80, 0x07, 0x9E, 0x48,
0x00, 0x00, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xF2, 0x8E, 0x04, 0x88, 0x44, 0x92, 0x48,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x04, 0x8C, 0x87, 0xDF, 0x48,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x8B, 0x00, 0x00, 0x48,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x04, 0xB9, 0xE7, 0xDE, 0x48,
0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x04, 0x88, 0x81, 0x12, 0x48,
0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3E, 0x03, 0x04, 0x88, 0x47, 0xDF, 0x48,
0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x04, 0xC0, 0x00, 0x00, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x79, 0x00, 0x03, 0x01, 0x04, 0x7F, 0xFF, 0xFF, 0x88,
0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x84, 0x80, 0x02, 0x81, 0x02, 0x00, 0x00, 0x00, 0x08,
0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x02, 0x80, 0x02, 0x81, 0x02, 0x00, 0x00, 0x00, 0x30,
0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x02, 0x01, 0x80, 0x02, 0x43, 0x01, 0xFF, 0xFF, 0xFF, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x01, 0x60, 0x0C, 0x00, 0x00, 0x02, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x00, 0x01, 0x1F, 0xF0, 0x00, 0x00, 0x02, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x38, 0x40, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x07, 0xC7, 0x80, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x28, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0xA0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xA3, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x22, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x44, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xC5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x0E, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xCF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t frame2[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x10, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x10, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x63, 0x01, 0xFF, 0xFF, 0xFF, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x02, 0x00, 0x00, 0x00, 0x30,
0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x01, 0x02, 0x80, 0x00, 0xC1, 0x02, 0x00, 0x00, 0x00, 0x08,
0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x04, 0x7F, 0xFF, 0xFF, 0x88,
0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x04, 0xC0, 0x08, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x04, 0x80, 0x0C, 0x71, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x10, 0x03, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x04, 0x80, 0x0F, 0xFF, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x10, 0x23, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x80, 0x08, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x00, 0x10, 0x30, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x01, 0xF0, 0x3B, 0x60, 0x00, 0x00, 0xF0, 0x8E, 0x04, 0x80, 0x0C, 0x71, 0xC8,
0x00, 0x00, 0x00, 0x0E, 0x00, 0x33, 0x60, 0x00, 0x0F, 0x00, 0x7E, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x10, 0x00, 0x23, 0x60, 0x00, 0xF0, 0x00, 0x5E, 0x04, 0x98, 0x4F, 0xFF, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x5E, 0x04, 0x96, 0x88, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x5E, 0x04, 0x91, 0x0F, 0xE0, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x5E, 0x04, 0x90, 0x88, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x5E, 0x04, 0x90, 0x4F, 0xFF, 0xC8,
0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x5E, 0x04, 0x90, 0x40, 0x00, 0x48,
0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x7E, 0x04, 0x80, 0x07, 0x9E, 0x48,
0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x8E, 0x04, 0x88, 0x44, 0x92, 0x48,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x04, 0x8C, 0x87, 0xDF, 0x48,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x8B, 0x00, 0x00, 0x48,
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x04, 0xB9, 0xE7, 0xDE, 0x48,
0x04, 0x00, 0x00, 0x00, 0x18, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x04, 0x88, 0x81, 0x12, 0x48,
0x0B, 0xFD, 0x00, 0x00, 0x18, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x04, 0x88, 0x47, 0xDF, 0x48,
0x08, 0x01, 0x00, 0x00, 0x14, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x04, 0xC0, 0x00, 0x00, 0xC8,
0x08, 0x00, 0x80, 0x00, 0x14, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x04, 0x7F, 0xFF, 0xFF, 0x88,
0x08, 0x3E, 0x80, 0x00, 0x12, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x02, 0x00, 0x00, 0x00, 0x08,
0x06, 0x05, 0x00, 0x00, 0x11, 0x00, 0x01, 0x02, 0x80, 0x00, 0xC1, 0x02, 0x00, 0x00, 0x00, 0x30,
0x02, 0x09, 0x00, 0x00, 0x10, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x01, 0xFF, 0xFF, 0xFF, 0xC0,
0x04, 0x3E, 0x80, 0x00, 0x10, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x80, 0x00, 0x10, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x40, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x38, 0x40, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x07, 0xC7, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x28, 0x40, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x50, 0x20, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0xA0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xA3, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x22, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x44, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xC5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x0E, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xCF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t frame3[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x23, 0x01, 0xFF, 0xFF, 0xFF, 0xC0,
0x00, 0x00, 0x00, 0x01, 0x00, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x02, 0x00, 0x00, 0x00, 0x30,
0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x02, 0x80, 0x00, 0x81, 0x02, 0x00, 0x00, 0x00, 0x08,
0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x04, 0x7F, 0xFF, 0xFF, 0x88,
0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x04, 0xC0, 0x08, 0x20, 0xC8,
0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x04, 0x80, 0x0C, 0x71, 0xC8,
0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x00, 0x00, 0x00, 0x01, 0x10, 0x03, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x04, 0x80, 0x0F, 0xFF, 0xC8,
0x01, 0x00, 0x00, 0x01, 0x10, 0x23, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x80, 0x08, 0x20, 0xC8,
0x02, 0x00, 0x00, 0x01, 0x10, 0x30, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x04, 0x04, 0x00, 0x01, 0xE0, 0x3B, 0x60, 0x00, 0x00, 0xF0, 0x8E, 0x04, 0x80, 0x0C, 0x71, 0xC8,
0x08, 0x04, 0x00, 0x0F, 0x00, 0x33, 0x60, 0x00, 0x0F, 0x00, 0x7E, 0x04, 0x80, 0x0B, 0xAE, 0xC8,
0x0C, 0x04, 0x00, 0x10, 0x00, 0x23, 0x60, 0x00, 0xF0, 0x00, 0x1E, 0x04, 0x98, 0x4F, 0xFF, 0xC8,
0x03, 0x02, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x1E, 0x04, 0x96, 0x88, 0x20, 0xC8,
0x00, 0xF2, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x1E, 0x04, 0x91, 0x0F, 0xE0, 0xC8,
0x00, 0x72, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x1E, 0x04, 0x90, 0x88, 0x20, 0xC8,
0x00, 0x82, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x1E, 0x04, 0x90, 0x4F, 0xFF, 0xC8,
0x03, 0x0A, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x1E, 0x04, 0x90, 0x40, 0x00, 0x48,
0x04, 0x0C, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x7E, 0x04, 0x80, 0x07, 0x9E, 0x48,
0x08, 0x4A, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x8E, 0x04, 0x88, 0x44, 0x92, 0x48,
0x08, 0xCD, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x04, 0x8C, 0x87, 0xDF, 0x48,
0x06, 0x01, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x8B, 0x00, 0x00, 0x48,
0x01, 0xC1, 0x00, 0x01, 0x10, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x04, 0xB9, 0xE7, 0xDE, 0x48,
0x04, 0x39, 0x00, 0x01, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x04, 0x88, 0x81, 0x12, 0x48,
0x0B, 0xFD, 0x00, 0x01, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x04, 0x88, 0x47, 0xDF, 0x48,
0x08, 0x01, 0x00, 0x01, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x04, 0xC0, 0x00, 0x00, 0xC8,
0x08, 0x00, 0x80, 0x01, 0x04, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x04, 0x7F, 0xFF, 0xFF, 0x88,
0x08, 0x3E, 0x80, 0x01, 0x02, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x02, 0x00, 0x00, 0x00, 0x08,
0x06, 0x05, 0x00, 0x01, 0x01, 0x00, 0x01, 0x02, 0x80, 0x00, 0x81, 0x02, 0x00, 0x00, 0x00, 0x30,
0x02, 0x09, 0x00, 0x01, 0x00, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x01, 0xFF, 0xFF, 0xFF, 0xC0,
0x04, 0x3E, 0x80, 0x01, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x80, 0x01, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x38, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x07, 0xC7, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x28, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x50, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0xA0, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xA3, 0x10, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x22, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x44, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xC5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x0E, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xCF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM frame4 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x23, 0x0F, 0xFF, 0xFF, 0xFE, 0x00,
0x00, 0x00, 0x00, 0x08, 0x00, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x10, 0x00, 0x00, 0x01, 0x80,
0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x01, 0x02, 0x80, 0x00, 0x81, 0x10, 0x00, 0x00, 0x00, 0x40,
0x00, 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x23, 0xFF, 0xFF, 0xFC, 0x40,
0x00, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x26, 0x00, 0x41, 0x06, 0x40,
0x03, 0xE0, 0x00, 0x08, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x24, 0x00, 0x5D, 0x76, 0x40,
0x04, 0x90, 0x00, 0x08, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x24, 0x00, 0x63, 0x8E, 0x40,
0x05, 0x28, 0x00, 0x08, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x24, 0x00, 0x5D, 0x76, 0x40,
0x05, 0x68, 0x00, 0x08, 0x10, 0x03, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x24, 0x00, 0x7F, 0xFE, 0x40,
0x02, 0x50, 0x00, 0x08, 0x10, 0x23, 0x00, 0x00, 0x00, 0x00, 0x07, 0x24, 0x00, 0x41, 0x06, 0x40,
0x01, 0xF8, 0x00, 0x08, 0x10, 0x30, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x24, 0x00, 0x5D, 0x76, 0x40,
0x03, 0x04, 0x00, 0x09, 0xE0, 0x3B, 0x60, 0x00, 0x00, 0xF0, 0x8F, 0x24, 0x00, 0x63, 0x8E, 0x40,
0x04, 0xC8, 0x00, 0x0E, 0x00, 0x33, 0x60, 0x00, 0x0F, 0x00, 0x7F, 0x24, 0x00, 0x5D, 0x76, 0x40,
0x02, 0x08, 0x00, 0x18, 0x00, 0x23, 0x60, 0x00, 0xF0, 0x00, 0x1F, 0x24, 0xC2, 0x7F, 0xFE, 0x40,
0x01, 0xC4, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x1F, 0x24, 0xB4, 0x41, 0x06, 0x40,
0x00, 0x3C, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x1F, 0x24, 0x88, 0x7F, 0x06, 0x40,
0x00, 0x72, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x1F, 0x24, 0x84, 0x41, 0x06, 0x40,
0x00, 0x82, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x1F, 0x24, 0x82, 0x7F, 0xFE, 0x40,
0x03, 0x0A, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x1F, 0x24, 0x82, 0x00, 0x02, 0x40,
0x04, 0x0C, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x7F, 0x24, 0x00, 0x3C, 0xF2, 0x40,
0x08, 0x4A, 0x00, 0x09, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x8F, 0x24, 0x42, 0x24, 0x92, 0x40,
0x08, 0xCD, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x24, 0x64, 0x3E, 0xFA, 0x40,
0x06, 0x01, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x24, 0x58, 0x00, 0x02, 0x40,
0x01, 0xC1, 0x00, 0x08, 0x10, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x25, 0xCF, 0x3E, 0xF2, 0x40,
0x04, 0x39, 0x00, 0x08, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x24, 0x44, 0x08, 0x92, 0x40,
0x0B, 0xFD, 0x00, 0x08, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x24, 0x42, 0x3E, 0xFA, 0x40,
0x08, 0x01, 0x00, 0x08, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x26, 0x00, 0x00, 0x06, 0x40,
0x08, 0x00, 0x80, 0x08, 0x04, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x23, 0xFF, 0xFF, 0xFC, 0x40,
0x08, 0x3E, 0x80, 0x08, 0x02, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x10, 0x00, 0x00, 0x00, 0x40,
0x06, 0x05, 0x00, 0x08, 0x01, 0x00, 0x01, 0x02, 0x80, 0x00, 0x81, 0x10, 0x00, 0x00, 0x01, 0x80,
0x02, 0x09, 0x00, 0x08, 0x00, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x0F, 0xFF, 0xFF, 0xFE, 0x00,
0x04, 0x3E, 0x80, 0x08, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x80, 0x08, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x38, 0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x07, 0xC7, 0x80, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x28, 0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x50, 0x20, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0xA0, 0x20, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xA3, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x22, 0x90, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x09, 0x44, 0x90, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0xC5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x0E, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xCF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM frame5 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x04, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x04, 0x20, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x02, 0x10, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x01, 0x88, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x00, 0x6B, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x07, 0x9C, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x64, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x13, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x08, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x04, 0x07, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x03, 0x9C, 0x80, 0x80, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x3E, 0x20, 0x00, 0x00, 0x00, 0x00,
0x07, 0xF4, 0x80, 0x80, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x23, 0x21, 0xFF, 0xFF, 0xFF, 0xC0,
0x04, 0x0B, 0x00, 0x80, 0x00, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x22, 0x00, 0x00, 0x00, 0x30,
0x03, 0x28, 0x00, 0x80, 0x01, 0x00, 0x01, 0x02, 0x80, 0x00, 0x81, 0x22, 0x00, 0x00, 0x00, 0x08,
0x05, 0x30, 0x00, 0x80, 0x02, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x24, 0x7F, 0xFF, 0xFF, 0x88,
0x04, 0x08, 0x00, 0x80, 0x04, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x24, 0xC0, 0x08, 0x20, 0xC8,
0x03, 0xF8, 0x00, 0x80, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x24, 0x80, 0x0B, 0xAE, 0xC8,
0x04, 0x90, 0x00, 0x80, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x24, 0x80, 0x0C, 0x71, 0xC8,
0x05, 0x28, 0x00, 0x80, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x24, 0x80, 0x0B, 0xAE, 0xC8,
0x05, 0x68, 0x00, 0x80, 0x10, 0x03, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x24, 0x80, 0x0F, 0xFF, 0xC8,
0x02, 0x50, 0x00, 0x80, 0x10, 0x23, 0x00, 0x00, 0x00, 0x00, 0x07, 0x24, 0x80, 0x08, 0x20, 0xC8,
0x01, 0xF8, 0x00, 0x80, 0x10, 0x30, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x24, 0x80, 0x0B, 0xAE, 0xC8,
0x03, 0x04, 0x00, 0x81, 0xE0, 0x3B, 0x60, 0x00, 0x00, 0xF0, 0x8E, 0x24, 0x80, 0x0C, 0x71, 0xC8,
0x04, 0x48, 0x00, 0x8E, 0x00, 0x33, 0x60, 0x00, 0x0F, 0x00, 0x7E, 0x24, 0x80, 0x0B, 0xAE, 0xC8,
0x04, 0xC8, 0x00, 0x90, 0x00, 0x23, 0x60, 0x00, 0xF0, 0x00, 0x1E, 0x24, 0x98, 0x4F, 0xFF, 0xC8,
0x02, 0x04, 0x00, 0xA3, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x1E, 0x24, 0x96, 0x88, 0x20, 0xC8,
0x01, 0xFC, 0x00, 0xA3, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x1E, 0x24, 0x91, 0x0F, 0xE0, 0xC8,
0x00, 0x72, 0x00, 0xA3, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x1E, 0x24, 0x90, 0x88, 0x20, 0xC8,
0x00, 0x82, 0x00, 0xA3, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x1E, 0x24, 0x90, 0x4F, 0xFF, 0xC8,
0x03, 0x0A, 0x00, 0x93, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x1E, 0x24, 0x90, 0x40, 0x00, 0x48,
0x04, 0x0C, 0x00, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x7E, 0x24, 0x80, 0x07, 0x9E, 0x48,
0x08, 0x4A, 0x00, 0x81, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x8E, 0x24, 0x88, 0x44, 0x92, 0x48,
0x08, 0xCD, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x24, 0x8C, 0x87, 0xDF, 0x48,
0x06, 0x01, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x24, 0x8B, 0x00, 0x00, 0x48,
0x01, 0xC1, 0x00, 0x80, 0x10, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x03, 0x24, 0xB9, 0xE7, 0xDE, 0x48,
0x04, 0x39, 0x00, 0x80, 0x08, 0x00, 0x3F, 0x0C, 0x03, 0xC0, 0x03, 0x24, 0x88, 0x81, 0x12, 0x48,
0x0B, 0xFD, 0x00, 0x80, 0x08, 0x00, 0xCC, 0x02, 0x00, 0x3C, 0x03, 0x24, 0x88, 0x47, 0xDF, 0x48,
0x08, 0x01, 0x00, 0x80, 0x04, 0x00, 0x70, 0x01, 0x00, 0x02, 0x01, 0x24, 0xC0, 0x00, 0x00, 0xC8,
0x08, 0x00, 0x80, 0x80, 0x04, 0x00, 0x00, 0x79, 0x00, 0x01, 0x01, 0x24, 0x7F, 0xFF, 0xFF, 0x88,
0x08, 0x3E, 0x80, 0x80, 0x02, 0x00, 0x00, 0x84, 0x80, 0x00, 0x81, 0x22, 0x00, 0x00, 0x00, 0x08,
0x06, 0x05, 0x00, 0x80, 0x01, 0x00, 0x01, 0x02, 0x80, 0x00, 0x81, 0x22, 0x00, 0x00, 0x00, 0x30,
0x02, 0x09, 0x00, 0x80, 0x00, 0x80, 0x02, 0x01, 0x80, 0x00, 0x43, 0x21, 0xFF, 0xFF, 0xFF, 0xC0,
0x04, 0x3E, 0x80, 0x80, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x23, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x80, 0x80, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x3E, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x38, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x07, 0xC7, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x28, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x04, 0x50, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x04, 0xA0, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0xA3, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x09, 0x22, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x09, 0x44, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0xC5, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
0x08, 0x09, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x08, 0x0E, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xCF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
void draw()
{
  if(frame==0)
   u8g.drawBitmapP( 0, 0, 16, 64, frame1);
  else if (frame == 1)
   u8g.drawBitmapP( 0, 0, 16, 64, frame2);
  else if(frame == 2)
   u8g.drawBitmapP( 0, 0, 16, 64, frame3);
  else if(frame == 3)
   u8g.drawBitmapP( 0, 0, 16, 64, frame4);
  else if(frame == 4)
   u8g.drawBitmapP( 0, 0, 16, 64, frame5);
}

void setup(void) {
}

void loop(void) {

 u8g.firstPage();
  do{
   draw();
 } while(u8g.nextPage());
 
 frame ++;
 if(frame>4)
  frame = 0;
 delay(16);
}

