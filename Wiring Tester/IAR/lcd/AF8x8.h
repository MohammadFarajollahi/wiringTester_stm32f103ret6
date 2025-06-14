/*
    created with FontEditor written by H. Reddmann
    HaReddmann at t-online dot de

    File Name           : AF8x8.h
    Date                : 3/3/2021
    Font size in bytes  : 0x0608, 1544
    Font width          : 9
    Font height         : 8
    Font first char     : 0x00
    Font last char      : 0xFE
    Font bits per pixel : 1
    Font is compressed  : false

    The font data are defined as

    struct _FONT_ {
     // common shared fields
       uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
       uint8_t    font_Width_in_Pixel_for_fixed_drawing;
       uint8_t    font_Height_in_Pixel_for_all_Characters;
       uint8_t    font_Bits_per_Pixels;
                    // if MSB are set then font is a compressed font
       uint8_t    font_First_Char;
       uint8_t    font_Last_Char;
       uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
                    // for each character the separate width in pixels,
                    // characters < 128 have an implicit virtual right empty row
                    // characters with font_Char_Widths[] == 0 are undefined

     // if compressed font then additional fields
       uint8_t    font_Byte_Padding;
                    // each Char in the table are aligned in size to this value
       uint8_t    font_RLE_Table[3];
                    // Run Length Encoding Table for compression
       uint8_t    font_Char_Size_in_Bytes[font_Last_Char - font_First_Char +1];
                    // for each char the size in (bytes / font_Byte_Padding) are stored,
                    // this get us the table to seek to the right beginning of each char
                    // in the font_data[].

     // for compressed and uncompressed fonts
       uint8_t    font_data[];
                    // bit field of all characters
    }
*/

#ifndef AF8x8_H
#define AF8x8_H


#define AF8x8_WIDTH 9
#define AF8x8_HEIGHT 8

const unsigned char   AF8x8[] = {
    0x06, 0x08, 0x09, 0x08, 0x01, 0x00, 0xFE,
    0x04, 0x00, 0x00, 0x00, 0x03, 0x03, 0x04, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x08, 0x08, 0x06, 
    0x03, 0x03, 0x05, 0x06, 0x06, 0x06, 0x05, 0x06, 0x06, 0x05, 0x06, 0x05, 0x04, 0x04, 0x04, 0x04, 
    0x03, 0x02, 0x04, 0x08, 0x06, 0x08, 0x07, 0x02, 0x04, 0x04, 0x06, 0x06, 0x02, 0x04, 0x02, 0x04, 
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x03, 0x06, 0x06, 0x06, 0x05, 
    0x08, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x04, 0x05, 0x06, 0x05, 0x08, 0x07, 0x07, 
    0x06, 0x07, 0x06, 0x07, 0x06, 0x06, 0x06, 0x08, 0x06, 0x06, 0x06, 0x03, 0x04, 0x03, 0x06, 0x06, 
    0x03, 0x06, 0x06, 0x05, 0x06, 0x06, 0x04, 0x06, 0x06, 0x02, 0x04, 0x05, 0x02, 0x08, 0x05, 0x06, 
    0x05, 0x05, 0x06, 0x05, 0x04, 0x05, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x03, 0x05, 0x08, 0x06, 
    0x05, 0x07, 0x04, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x08, 0x06, 0x06, 0x07, 0x04, 0x06, 
    0x08, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x05, 0x08, 0x03, 0x07, 0x04, 0x08, 0x06, 0x07, 0x06, 
    0x07, 0x03, 0x03, 0x07, 0x06, 0x05, 0x06, 0x06, 0x09, 0x09, 0x06, 0x09, 0x06, 0x06, 0x09, 0x06, 
    0x05, 0x05, 0x06, 0x00, 0x00, 0x08, 0x00, 0x03, 0x00, 0x00, 0x03, 0x09, 0x00, 0x00, 0x00, 0x05, 
    0x04, 0x03, 0x05, 0x04, 0x04, 0x02, 0x07, 0x02, 0x07, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04, 
    0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x07, 0x06, 0x06, 0x05, 0x05, 0x00, 0x08, 0x07, 0x08, 
    0x00, 0x06, 0x00, 0x07, 0x06, 0x04, 0x04, 0x06, 0x00, 0x06, 0x00, 0x00, 0x07, 0x08, 0x04, 0x00, 
    0x05, 0x05, 0x03, 0x03, 0x00, 0x05, 0x05, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x05, 0x07, 
    0x00, 0x1E, 0x20, 0x20, 0x20, 0xA0, 0x18, 0x22, 0x22, 0x18, 0x24, 0x26, 0x20, 0x18, 0x20, 0x28, 
    0x24, 0xA8, 0x30, 0x20, 0x40, 0xA0, 0xA8, 0xA4, 0x28, 0xB0, 0x20, 0x20, 0x28, 0x24, 0x28, 0x30, 
    0x20, 0x40, 0xA0, 0xA8, 0xA4, 0x28, 0x30, 0x20, 0x22, 0x28, 0x24, 0x28, 0x30, 0x20, 0x40, 0xA2, 
    0xA8, 0xA4, 0x28, 0x30, 0x20, 0x20, 0x20, 0x18, 0x20, 0x18, 0x20, 0x24, 0x18, 0x20, 0x20, 0x1A, 
    0x22, 0x1A, 0x20, 0x24, 0x18, 0x20, 0x38, 0x30, 0x28, 0x24, 0x18, 0x00, 0x18, 0x18, 0x00, 0x06, 
    0x7C, 0x00, 0x06, 0x0C, 0x74, 0x02, 0x00, 0x06, 0x0C, 0x76, 0x04, 0x02, 0x00, 0x04, 0x0E, 0x7C, 
    0x0A, 0x0A, 0x00, 0x30, 0x4A, 0x24, 0x48, 0x30, 0x00, 0x40, 0x2C, 0x1A, 0x0A, 0x00, 0x06, 0x18, 
    0x60, 0x18, 0x06, 0x00, 0x60, 0x18, 0x06, 0x18, 0x60, 0x00, 0x04, 0x0A, 0x3C, 0x40, 0x20, 0x38, 
    0x32, 0x28, 0x24, 0x18, 0x20, 0x28, 0x34, 0x24, 0x10, 0x00, 0x18, 0x18, 0x00, 0x00, 0x38, 0x34, 
    0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00, 0x5C, 0x5A, 0x00, 0x00, 0x00, 0x00, 0x5E, 0x00, 0x0E, 0x00, 
    0x0E, 0x00, 0x20, 0xE8, 0x38, 0xEE, 0x38, 0x2E, 0x08, 0x00, 0x48, 0x54, 0xD6, 0x54, 0x24, 0x00, 
    0x84, 0x4A, 0x24, 0x10, 0x48, 0xA4, 0x42, 0x00, 0x6C, 0x92, 0x92, 0xAC, 0x40, 0xA0, 0x00, 0x0E, 
    0x00, 0x38, 0x44, 0x82, 0x00, 0x82, 0x44, 0x38, 0x00, 0x28, 0x10, 0x7C, 0x10, 0x28, 0x00, 0x10, 
    0x10, 0x7C, 0x10, 0x10, 0x00, 0xE0, 0x00, 0x10, 0x10, 0x10, 0x00, 0x20, 0x00, 0xC0, 0x38, 0x06, 
    0x00, 0x7C, 0xA2, 0x92, 0x8A, 0x7C, 0x00, 0x00, 0x84, 0xFE, 0x80, 0x00, 0x00, 0xC4, 0xA2, 0x92, 
    0x92, 0x8C, 0x00, 0x44, 0x82, 0x92, 0x92, 0x6C, 0x00, 0x30, 0x28, 0x24, 0xFE, 0x20, 0x00, 0x4E, 
    0x8A, 0x8A, 0x8A, 0x72, 0x00, 0x78, 0x94, 0x92, 0x92, 0x60, 0x00, 0x02, 0x82, 0x62, 0x1A, 0x06, 
    0x00, 0x6C, 0x92, 0x92, 0x92, 0x6C, 0x00, 0x0C, 0x92, 0x92, 0x52, 0x3C, 0x00, 0x6C, 0x00, 0x80, 
    0x6C, 0x00, 0x10, 0x28, 0x28, 0x44, 0x44, 0x00, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00, 0x44, 0x44, 
    0x28, 0x28, 0x10, 0x00, 0x04, 0xA2, 0x12, 0x0C, 0x00, 0x38, 0x44, 0xB2, 0xAA, 0xBA, 0x24, 0x18, 
    0x00, 0xF0, 0x2C, 0x22, 0x22, 0x2C, 0xF0, 0x00, 0xFE, 0x92, 0x92, 0x92, 0x6C, 0x00, 0x7C, 0x82, 
    0x82, 0x82, 0x44, 0x00, 0xFE, 0x82, 0x82, 0x82, 0x7C, 0x00, 0xFE, 0x92, 0x92, 0x92, 0x82, 0x00, 
    0xFE, 0x12, 0x12, 0x12, 0x02, 0x00, 0x7C, 0x82, 0x92, 0x92, 0x74, 0x00, 0xFE, 0x10, 0x10, 0x10, 
    0xFE, 0x00, 0x82, 0xFE, 0x82, 0x00, 0x80, 0x82, 0x82, 0x7E, 0x00, 0xFE, 0x10, 0x28, 0x44, 0x82, 
    0x00, 0xFE, 0x80, 0x80, 0x80, 0x00, 0xFE, 0x06, 0x18, 0x60, 0x18, 0x06, 0xFE, 0x00, 0xFE, 0x06, 
    0x18, 0x60, 0x80, 0xFE, 0x00, 0x38, 0x44, 0x82, 0x82, 0x44, 0x38, 0x00, 0xFE, 0x22, 0x22, 0x22, 
    0x1C, 0x00, 0x38, 0x44, 0x82, 0xA2, 0x44, 0xB8, 0x00, 0xFE, 0x12, 0x32, 0x52, 0x8C, 0x00, 0x4C, 
    0x92, 0x92, 0x92, 0x92, 0x64, 0x00, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x00, 0x7E, 0x80, 0x80, 0x80, 
    0x7E, 0x00, 0x0E, 0x70, 0x80, 0x70, 0x0E, 0x00, 0x0E, 0x70, 0x80, 0x7C, 0x80, 0x70, 0x0E, 0x00, 
    0xC6, 0x28, 0x10, 0x28, 0xC6, 0x00, 0x06, 0x08, 0xF0, 0x08, 0x06, 0x00, 0xC2, 0xA2, 0x92, 0x8A, 
    0x86, 0x00, 0xFE, 0x82, 0x00, 0x06, 0x38, 0xC0, 0x00, 0x82, 0xFE, 0x00, 0x08, 0x04, 0x02, 0x04, 
    0x08, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x02, 0x04, 0x00, 0x60, 0x94, 0x94, 0x94, 0xF8, 
    0x00, 0xFE, 0x50, 0x88, 0x88, 0x70, 0x00, 0x78, 0x84, 0x84, 0x48, 0x00, 0x70, 0x88, 0x88, 0x50, 
    0xFE, 0x00, 0x78, 0x94, 0x94, 0x94, 0x58, 0x00, 0x08, 0xFC, 0x0A, 0x00, 0x4C, 0x92, 0x92, 0x94, 
    0x7E, 0x00, 0xFE, 0x10, 0x08, 0x08, 0xF0, 0x00, 0xFA, 0x00, 0x80, 0x88, 0x7A, 0x00, 0xFE, 0x20, 
    0x50, 0x88, 0x00, 0xFE, 0x00, 0xF8, 0x10, 0x08, 0xF8, 0x08, 0x08, 0xF0, 0x00, 0xF8, 0x08, 0x08, 
    0xF0, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0xFC, 0x24, 0x24, 0x18, 0x00, 0x18, 0x24, 0x24, 
    0xFC, 0x00, 0xF8, 0x10, 0x08, 0x08, 0x10, 0x00, 0x58, 0x94, 0xA4, 0x68, 0x00, 0x7C, 0x88, 0x88, 
    0x00, 0x78, 0x80, 0x40, 0xF8, 0x00, 0x18, 0x60, 0x80, 0x60, 0x18, 0x00, 0x78, 0x80, 0x70, 0x80, 
    0x78, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00, 0x86, 0x88, 0x48, 0x3E, 0x00, 0x88, 0xC8, 0xA8, 
    0x98, 0x00, 0x10, 0x6C, 0x82, 0x82, 0x00, 0x00, 0x7C, 0x00, 0x82, 0x82, 0x6C, 0x10, 0x00, 0x18, 
    0x20, 0x20, 0x10, 0x08, 0x08, 0x30, 0x00, 0x02, 0x60, 0x94, 0x8A, 0x96, 0x20, 0x20, 0x22, 0x28, 
    0x34, 0x18, 0x18, 0x24, 0xA0, 0xA0, 0xA0, 0x20, 0x18, 0x00, 0x40, 0x60, 0x20, 0x20, 0x22, 0x22, 
    0x28, 0x34, 0x18, 0x08, 0x0C, 0x7E, 0x0C, 0x08, 0x00, 0x28, 0x6C, 0xFE, 0x6C, 0x28, 0x00, 0x0C, 
    0x1E, 0x3C, 0x1E, 0x0C, 0x00, 0x0C, 0x12, 0x24, 0x12, 0x0C, 0x00, 0x20, 0x20, 0x38, 0x20, 0x18, 
    0x20, 0x24, 0x18, 0x10, 0x1E, 0x5F, 0x1E, 0x10, 0x00, 0x20, 0x24, 0x2A, 0x2A, 0x2A, 0x12, 0x40, 
    0xA0, 0xA8, 0x24, 0xA8, 0xB0, 0xA0, 0x80, 0x80, 0x44, 0x36, 0x18, 0x18, 0x3C, 0x7E, 0xFF, 0x00, 
    0x18, 0x24, 0x20, 0x2C, 0x2A, 0x2B, 0x2B, 0x13, 0xC0, 0xF8, 0x04, 0x62, 0x7F, 0x00, 0x1C, 0x27, 
    0xE4, 0x27, 0x1C, 0x00, 0x60, 0xFE, 0xF9, 0xFE, 0x60, 0x00, 0x70, 0x8C, 0x83, 0x8C, 0x70, 0x00, 
    0x20, 0x20, 0x78, 0xD4, 0x28, 0x20, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x10, 0x10, 0x10, 
    0x10, 0x18, 0x24, 0x20, 0x2C, 0x2A, 0x2A, 0x2A, 0x12, 0x00, 0xC0, 0xC0, 0x40, 0xA0, 0xA8, 0xA4, 
    0x28, 0xB0, 0x20, 0x44, 0x28, 0x10, 0x00, 0x70, 0x88, 0x80, 0x90, 0xA8, 0x48, 0x10, 0x20, 0x20, 
    0xA8, 0xA4, 0xA8, 0x30, 0x20, 0x40, 0xA0, 0xA8, 0x24, 0xA8, 0xB0, 0xA0, 0x00, 0x24, 0x38, 0x20, 
    0x1E, 0x20, 0x38, 0x40, 0x80, 0x8C, 0x92, 0x92, 0x64, 0x38, 0x34, 0x00, 0x44, 0x46, 0x32, 0x03, 
    0x05, 0xFF, 0xFF, 0x05, 0x03, 0x00, 0xC0, 0xC0, 0x00, 0xF0, 0xF0, 0x00, 0x00, 0x26, 0x28, 0x30, 
    0x3E, 0x7E, 0x79, 0x49, 0x79, 0x7E, 0x00, 0x7E, 0x79, 0x49, 0x79, 0x78, 0x00, 0xC0, 0xC0, 0x00, 
    0xF0, 0xF0, 0x00, 0xFC, 0xFC, 0x00, 0x3C, 0x42, 0x99, 0xA5, 0xA5, 0xA5, 0x42, 0x3C, 0x00, 0xFC, 
    0xFC, 0x00, 0xFF, 0xFF, 0x00, 0x10, 0x38, 0x7C, 0xFE, 0x10, 0x38, 0x7C, 0xFE, 0x00, 0xFE, 0x83, 
    0x81, 0x83, 0xFE, 0x00, 0xFE, 0xE3, 0xE1, 0xE3, 0xFE, 0x00, 0x3C, 0x42, 0xBD, 0x95, 0x95, 0xA9, 
    0x42, 0x3C, 0x00, 0xFE, 0xFB, 0xF9, 0xFB, 0xFE, 0x00, 0x00, 0x0E, 0x0A, 0x0E, 0x00, 0x00, 0x24, 
    0x2E, 0x24, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x30, 0x48, 0x40, 0x40, 0x50, 0x58, 0x28, 
    0x08, 0x30, 0x30, 0x00, 0x5C, 0x5A, 0x00, 0xFE, 0x7C, 0x38, 0x10, 0xFE, 0x7C, 0x38, 0x10, 0x00, 
    0x00, 0x0C, 0x12, 0xB2, 0x04, 0x20, 0xA0, 0xA4, 0x18, 0x20, 0x18, 0x14, 0x00, 0x04, 0x02, 0x7A, 
    0x02, 0x00, 0x04, 0x06, 0xF2, 0x80, 0x88, 0x54, 0x38, 0x00, 0x7E, 0x30, 0x48, 0x40, 0x48, 0x54, 
    0x34, 0x04, 0x00, 0x7E, 0x18, 0x24, 0x20, 0xA0, 0x20, 0x20, 0x18, 0x30, 0x4A, 0x52, 0x20, 0x18, 
    0x24, 0x20, 0x22, 0x22, 0x20, 0x18, 0x18, 0x24, 0x20, 0x24, 0x26, 0x20, 0x18, 0x40, 0xA0, 0xA8, 
    0xA4, 0x28, 0xB0, 0x20, 0x40, 0xA0, 0xA8, 0xA4, 0x28, 0x30, 0x20, 0x40, 0xA2, 0xA8, 0xA4, 0x28, 
    0x30, 0x20, 0x00, 0x20, 0x24, 0x18, 0x00, 0x20, 0x25, 0x18, 0x80, 0x80, 0x40, 0x30, 0x80, 0x80, 
    0x44, 0x30, 0x70, 0x88, 0x80, 0x78, 0x20, 0x18, 0x20, 0x18, 0x70, 0x88, 0x80, 0x78, 0x22, 0x1A, 
    0x22, 0x18, 0x70, 0x88, 0x80, 0x78, 0x30, 0x28, 0x24, 0x18, 0x70, 0x88, 0x80, 0x78, 0x32, 0x28, 
    0x24, 0x18, 0x00, 0x22, 0x14, 0x08, 0x14, 0x22, 0x00, 0x20, 0x3E, 0x30, 0x28, 0x24, 0x18, 0x20, 
    0x3E, 0x30, 0x2A, 0x24, 0x18, 0x60, 0x90, 0x98, 0x94, 0x94, 0x62, 0x90, 0x98, 0x94, 0x94, 0x60, 
    0x90, 0x80, 0x84, 0x80, 0xA0, 0xD0, 0x60, 0x30, 0x4A, 0x82, 0x80, 0x8C, 0x52, 0x3C, 0x18, 0x24, 
    0x20, 0x2C, 0x2A, 0x2A, 0x2A, 0x12, 0x30, 0x48, 0x40, 0x40, 0x20, 0x1E, 0x60, 0x90, 0x08, 0x1C, 
    0x22, 0x24, 0x18, 0x70, 0x88, 0x80, 0x82, 0x40, 0x38, 0x0C, 0x12, 0x14, 0x08, 0x80, 0x88, 0x54, 
    0x38, 0x08, 0x14, 0x12, 0x0C, 0x10, 0x20, 0x10, 0x29, 0x25, 0x18, 0x20, 0x40, 0x38, 0x44, 0x80, 
    0x8C, 0x92, 0x92, 0x64, 0x70, 0x88, 0x80, 0x80, 0x90, 0xA8, 0x64, 0x04, 0x00, 0x04, 0x72, 0x04, 
    0x20, 0x28, 0x34, 0x2C, 0x20, 0x60, 0x94, 0x8A, 0x96, 0x20, 0x20, 0x22, 0x18, 0x20, 0x20, 0x1E, 
    0x22, 0x28, 0x34, 0x24, 0x10, 0x22, 0x28, 0x34, 0x2C, 0x20, 0x20, 0x20, 0x18, 0x24, 0x18, 0x20, 
    0x2C, 0x2A, 0x2B, 0x2B, 0x13, 0x20, 0xA0, 0xA0, 0xA4, 0x18, 0x20, 0x40, 0x50, 0x2A, 0x54, 0x48, 
    0x30, 0x00
};

#endif

