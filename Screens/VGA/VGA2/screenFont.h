// bit patterns for the CP437 font, ROTATED, INVERTED

// To save rendering time, they are ordered by line (ie. line 1, line 2) and then 
//  indexed by character.

int screen_font [8] [256] PROGMEM = {
// Row 1
 { 
  0xFF, 0xC0, 0xC0, 0xC9, 0xF7, 0xE3, 0xF7, 0xFF, 0x80, 0xFF, 0x80, 0xF8, 0xE1, 0xE0, 0xC0, 0xB3, 
  0xBF, 0xFE, 0xF3, 0xCC, 0xC0, 0xE0, 0xFF, 0xF3, 0xF3, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xE7, 0xC9, 0xC9, 0xE7, 0xFF, 0xE3, 0xCF, 0xF3, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
  0xC1, 0xE7, 0xC3, 0xC3, 0xF1, 0x81, 0xE3, 0x81, 0xC3, 0xC3, 0xFF, 0xFF, 0xF3, 0xFF, 0xCF, 0xC3, 
  0xC1, 0xE7, 0x81, 0xE1, 0x83, 0x80, 0x80, 0xE1, 0x99, 0xC3, 0xF0, 0x8C, 0x87, 0x9C, 0x9C, 0xE3, 
  0x81, 0xC3, 0x81, 0xC3, 0x81, 0x99, 0x99, 0x9C, 0x9C, 0x99, 0x80, 0xC3, 0x9F, 0xC3, 0xF7, 0xFF, 
  0xE7, 0xFF, 0x8F, 0xFF, 0xF1, 0xFF, 0xE3, 0xFF, 0x8F, 0xE7, 0xF9, 0x8F, 0xC7, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xF3, 0x8F, 0xC4, 0xFF, 
  0xC3, 0xFF, 0xF1, 0xC0, 0x99, 0x8F, 0xE7, 0xFF, 0xC0, 0x99, 0x8F, 0x99, 0xC1, 0x8F, 0x9C, 0xE7, 
  0xF1, 0xFF, 0xE0, 0xC3, 0xFF, 0xFF, 0xC3, 0xFF, 0xFF, 0x9E, 0x99, 0xF3, 0xE3, 0x99, 0x83, 0xF8, 
  0xF1, 0xE3, 0xFF, 0xFF, 0xFF, 0x81, 0xE1, 0xE3, 0xE7, 0xFF, 0xFF, 0x9E, 0x9E, 0xF3, 0xFF, 0xFF, 
  0xEE, 0xD5, 0x92, 0xF3, 0xF3, 0xF3, 0xE4, 0xFF, 0xFF, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xF3, 0xFF, 
  0xF3, 0xF3, 0xFF, 0xF3, 0xFF, 0xF3, 0xF3, 0xE4, 0xE4, 0xFF, 0xE4, 0xFF, 0xE4, 0xFF, 0xE4, 0xF3, 
  0xE4, 0xFF, 0xFF, 0xE4, 0xF3, 0xFF, 0xFF, 0xE4, 0xF3, 0xF3, 0xFF, 0x80, 0xFF, 0x87, 0xF8, 0x80, 
  0xFF, 0xFF, 0xFF, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0x81, 0xE3, 0xE3, 0xF1, 0xFF, 0xFC, 0xE3, 0xC3, 
  0xFF, 0xE7, 0xCF, 0xF3, 0xF8, 0xF3, 0xE7, 0xFF, 0xE3, 0xFF, 0xFF, 0xF8, 0xC3, 0xC7, 0xFF, 0xFF, 
  }, 
// Row 2
 { 
  0xFF, 0xBF, 0x80, 0x80, 0xE3, 0xC1, 0xF7, 0xFF, 0x80, 0xE1, 0x9E, 0xFC, 0xCC, 0xE6, 0xCE, 0xD2, 
  0x8F, 0xF8, 0xE1, 0xCC, 0x92, 0xCE, 0xFF, 0xE1, 0xE1, 0xF3, 0xF3, 0xE7, 0xFF, 0xED, 0xF3, 0x80, 
  0xFF, 0xC3, 0xC9, 0xC9, 0xC1, 0x9C, 0xC9, 0xCF, 0xE7, 0xE7, 0xCC, 0xE7, 0xFF, 0xFF, 0xFF, 0xF9, 
  0x9C, 0xC7, 0x99, 0x99, 0xE1, 0x9F, 0xCF, 0x99, 0x99, 0x99, 0xE7, 0xE7, 0xE7, 0xFF, 0xE7, 0x99, 
  0x9C, 0xC3, 0xCC, 0xCC, 0xC9, 0xCE, 0xCE, 0xCC, 0x99, 0xE7, 0xF9, 0xCC, 0xCF, 0x88, 0x8C, 0xC9, 
  0xCC, 0x99, 0xCC, 0x99, 0xA5, 0x99, 0x99, 0x9C, 0x9C, 0x99, 0x9C, 0xCF, 0xCF, 0xF3, 0xE3, 0xFF, 
  0xE7, 0xFF, 0xCF, 0xFF, 0xF9, 0xFF, 0xC9, 0xFF, 0xCF, 0xFF, 0xFF, 0xCF, 0xE7, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xF3, 0xE7, 0x91, 0xF7, 
  0x99, 0x99, 0xFF, 0x9E, 0xFF, 0xFF, 0xE7, 0xFF, 0x9E, 0xFF, 0xFF, 0xFF, 0x9C, 0xFF, 0xE3, 0xE7, 
  0xFF, 0xFF, 0xC9, 0x99, 0x99, 0x8F, 0x99, 0x8F, 0x99, 0xF3, 0xFF, 0xF3, 0xC9, 0x99, 0x99, 0xF2, 
  0xFF, 0xFF, 0xF1, 0xF1, 0x83, 0xFF, 0xC9, 0xC9, 0xFF, 0xFF, 0xFF, 0x9C, 0x9C, 0xF3, 0xE6, 0x99, 
  0xBB, 0xAA, 0xC4, 0xF3, 0xF3, 0xF3, 0xE4, 0xFF, 0xFF, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xF3, 0xFF, 
  0xF3, 0xF3, 0xFF, 0xF3, 0xFF, 0xF3, 0xF3, 0xE4, 0xE4, 0xFF, 0xE4, 0xFF, 0xE4, 0xFF, 0xE4, 0xF3, 
  0xE4, 0xFF, 0xFF, 0xE4, 0xF3, 0xFF, 0xFF, 0xE4, 0xF3, 0xF3, 0xFF, 0x80, 0xFF, 0x87, 0xF8, 0x80, 
  0xFF, 0xC3, 0x81, 0x80, 0x99, 0xFF, 0xCC, 0xC4, 0xE7, 0xC9, 0xC9, 0xE7, 0xFF, 0xF9, 0xCF, 0x99, 
  0x81, 0xE7, 0xE7, 0xE7, 0xF2, 0xF3, 0xE7, 0xC4, 0xC9, 0xFF, 0xFF, 0xF9, 0xC9, 0xF3, 0xFF, 0xFF, 
  }, 
// Row 3
 { 
  0xFF, 0xAD, 0x92, 0x80, 0xC1, 0xE3, 0xE3, 0xF3, 0x8C, 0xCC, 0xB3, 0xF8, 0xCC, 0xE0, 0xC0, 0xE1, 
  0x83, 0xE0, 0xC0, 0xCC, 0x92, 0xE3, 0xFF, 0xC0, 0xC0, 0xF3, 0xF9, 0xCF, 0x9F, 0xCC, 0xE1, 0x80, 
  0xFF, 0xC3, 0xC9, 0x80, 0x9F, 0x99, 0xE3, 0x9F, 0xCF, 0xF3, 0xE1, 0xE7, 0xFF, 0xFF, 0xFF, 0xF3, 
  0x98, 0xE7, 0xF9, 0xF9, 0xC9, 0x83, 0x9F, 0xF9, 0x99, 0x99, 0xE7, 0xE7, 0xCF, 0x81, 0xF3, 0xF9, 
  0x90, 0x99, 0xCC, 0x9F, 0xCC, 0xCB, 0xCB, 0x9F, 0x99, 0xE7, 0xF9, 0xC9, 0xCF, 0x80, 0x84, 0x9C, 
  0xCC, 0x99, 0xCC, 0x8F, 0xE7, 0x99, 0x99, 0x9C, 0xC9, 0x99, 0xB9, 0xCF, 0xE7, 0xF3, 0xC9, 0xFF, 
  0xF3, 0xC3, 0xCF, 0xC3, 0xF9, 0xC3, 0xCF, 0xC4, 0xC9, 0xC7, 0xF9, 0xCC, 0xE7, 0x99, 0x83, 0xC3, 
  0x91, 0xC4, 0x91, 0xC1, 0xC1, 0x99, 0x99, 0x9C, 0x9C, 0x99, 0x81, 0xE7, 0xF3, 0xE7, 0xFF, 0xE3, 
  0x9F, 0xFF, 0xC3, 0xE1, 0xC3, 0xC3, 0xC3, 0xC3, 0xE1, 0xC3, 0xC3, 0xC7, 0xE3, 0xC7, 0xC9, 0xFF, 
  0x81, 0xC0, 0x99, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE1, 0x99, 0xC0, 0xCD, 0xC3, 0x99, 0xF3, 
  0xC3, 0xC7, 0xFF, 0xFF, 0xFF, 0x99, 0xC9, 0xC9, 0xE7, 0xFF, 0xFF, 0x99, 0x99, 0xFF, 0xCC, 0xCC, 
  0xEE, 0xD5, 0x92, 0xF3, 0xF3, 0x83, 0xE4, 0xFF, 0x83, 0x84, 0xE4, 0x80, 0x84, 0xE4, 0x83, 0xFF, 
  0xF3, 0xF3, 0xFF, 0xF3, 0xFF, 0xF3, 0xF0, 0xE4, 0xE4, 0xE0, 0x84, 0x80, 0xE4, 0x80, 0x84, 0x80, 
  0xE4, 0x80, 0xFF, 0xE4, 0xF0, 0xF0, 0xFF, 0xE4, 0x80, 0xF3, 0xFF, 0x80, 0xFF, 0x87, 0xF8, 0x80, 
  0xC4, 0x99, 0x99, 0xC9, 0xCF, 0xC0, 0xCC, 0x91, 0xC3, 0x9C, 0x9C, 0xF3, 0xC0, 0xC0, 0x9F, 0x99, 
  0xFF, 0x81, 0xF3, 0xCF, 0xF2, 0xF3, 0xFF, 0x91, 0xC9, 0xFF, 0xFF, 0xF9, 0xC9, 0xE7, 0xE1, 0xFF, 
  }, 
// Row 4
 { 
  0xFF, 0xBF, 0x80, 0x80, 0x80, 0x80, 0xC1, 0xE1, 0x9E, 0xDE, 0xA1, 0xC1, 0xCC, 0xE7, 0xCE, 0x8C, 
  0x80, 0x80, 0xF3, 0xCC, 0xC2, 0xC9, 0xFF, 0xF3, 0xF3, 0xF3, 0x80, 0x80, 0x9F, 0x80, 0xC0, 0xC0, 
  0xFF, 0xE7, 0xFF, 0xC9, 0xC3, 0xF3, 0xC4, 0xFF, 0xCF, 0xF3, 0x80, 0x81, 0xFF, 0x81, 0xFF, 0xE7, 
  0x90, 0xE7, 0xE3, 0xE3, 0x99, 0xF9, 0x83, 0xF3, 0xC3, 0xC1, 0xFF, 0xFF, 0x9F, 0xFF, 0xF9, 0xF3, 
  0x90, 0x99, 0xC1, 0x9F, 0xCC, 0xC3, 0xC3, 0x9F, 0x81, 0xE7, 0xF9, 0xC3, 0xCF, 0x80, 0x90, 0x9C, 
  0xC1, 0x99, 0xC1, 0xC7, 0xE7, 0x99, 0x99, 0x94, 0xE3, 0xC3, 0xF3, 0xCF, 0xF3, 0xF3, 0x9C, 0xFF, 
  0xFF, 0xF9, 0xC1, 0x99, 0xC1, 0x99, 0x87, 0x99, 0xC4, 0xE7, 0xF9, 0xC9, 0xE7, 0x80, 0x99, 0x99, 
  0xCC, 0x99, 0xC4, 0x9F, 0xE7, 0x99, 0x99, 0x94, 0xC9, 0x99, 0xB3, 0x8F, 0xFF, 0xF1, 0xFF, 0xC9, 
  0x99, 0x99, 0x99, 0xFC, 0xF9, 0xF9, 0xF9, 0x9F, 0xCC, 0x99, 0x99, 0xE7, 0xF3, 0xE7, 0x9C, 0xC3, 
  0xCF, 0xF9, 0x80, 0xC3, 0xC3, 0xC3, 0x99, 0x99, 0x99, 0xCC, 0x99, 0x9F, 0x87, 0x81, 0x82, 0xE1, 
  0xF9, 0xE7, 0xC3, 0x99, 0x83, 0x89, 0xE0, 0xE3, 0xCF, 0x81, 0x81, 0x90, 0x92, 0xF3, 0x99, 0xE6, 
  0xBB, 0xAA, 0x88, 0xF3, 0xF3, 0xF3, 0xE4, 0xFF, 0xF3, 0xFC, 0xE4, 0xFC, 0xFC, 0xE4, 0xF3, 0xFF, 
  0xF3, 0xF3, 0xFF, 0xF3, 0xFF, 0xF3, 0xF3, 0xE4, 0xE7, 0xE7, 0xFF, 0xFF, 0xE7, 0xFF, 0xFF, 0xFF, 
  0xE4, 0xFF, 0xFF, 0xE4, 0xF3, 0xF3, 0xFF, 0xE4, 0xF3, 0xF3, 0xFF, 0x80, 0xFF, 0x87, 0xF8, 0x80, 
  0x91, 0x83, 0x9F, 0xC9, 0xE7, 0x93, 0xCC, 0xF3, 0x99, 0x80, 0x9C, 0xC1, 0x92, 0x92, 0x83, 0x99, 
  0x81, 0xE7, 0xE7, 0xE7, 0xF3, 0xF3, 0x81, 0xFF, 0xE3, 0xF3, 0xFF, 0xF9, 0xC9, 0xCF, 0xE1, 0xFF, 
  }, 
// Row 5
 { 
  0xFF, 0xA1, 0x9E, 0xC1, 0xC1, 0x80, 0x80, 0xE1, 0x9E, 0xDE, 0xA1, 0x99, 0xE1, 0xE7, 0xCE, 0x8C, 
  0x83, 0xE0, 0xF3, 0xCC, 0xF2, 0xC9, 0xC0, 0xC0, 0xF3, 0xC0, 0xF9, 0xCF, 0x9F, 0xCC, 0x80, 0xE1, 
  0xFF, 0xE7, 0xFF, 0x80, 0xF9, 0xE7, 0x91, 0xFF, 0xCF, 0xF3, 0xE1, 0xE7, 0xFF, 0xFF, 0xFF, 0xCF, 
  0x84, 0xE7, 0xCF, 0xF9, 0x80, 0xF9, 0x99, 0xE7, 0x99, 0xF9, 0xFF, 0xFF, 0xCF, 0xFF, 0xF3, 0xE7, 
  0x90, 0x81, 0xCC, 0x9F, 0xCC, 0xCB, 0xCB, 0x98, 0x99, 0xE7, 0x99, 0xC9, 0xCE, 0x94, 0x98, 0x9C, 
  0xCF, 0x91, 0xC9, 0xF1, 0xE7, 0x99, 0x99, 0x80, 0xE3, 0xE7, 0xE6, 0xCF, 0xF9, 0xF3, 0xFF, 0xFF, 
  0xFF, 0xC1, 0xCC, 0x9F, 0x99, 0x81, 0xCF, 0x99, 0xCC, 0xE7, 0xF9, 0xC3, 0xE7, 0x80, 0x99, 0x99, 
  0xCC, 0x99, 0xCC, 0xC3, 0xE7, 0x99, 0x99, 0x80, 0xE3, 0x99, 0xE7, 0xE7, 0xF3, 0xE7, 0xFF, 0x9C, 
  0xC3, 0x99, 0x81, 0xE0, 0xC1, 0xC1, 0xC1, 0x9F, 0xC0, 0x81, 0x81, 0xE7, 0xF3, 0xE7, 0x80, 0x99, 
  0xC3, 0xC0, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xCC, 0x99, 0x9F, 0xCF, 0xE7, 0x9C, 0xF3, 
  0xC1, 0xE7, 0x99, 0x99, 0x99, 0x81, 0xFF, 0xFF, 0x9F, 0x9F, 0xF9, 0xE6, 0xE4, 0xF3, 0xCC, 0xCC, 
  0xEE, 0xD5, 0x92, 0xF3, 0x83, 0x83, 0x84, 0x80, 0x83, 0x84, 0xE4, 0x84, 0x80, 0x80, 0x83, 0x83, 
  0xF0, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF0, 0xE4, 0xE0, 0xE4, 0x80, 0x84, 0xE4, 0x80, 0x84, 0x80, 
  0x80, 0x80, 0x80, 0xE0, 0xF0, 0xF0, 0xE0, 0x80, 0x80, 0x83, 0xF0, 0x80, 0x80, 0x87, 0xF8, 0xFF, 
  0x9B, 0x99, 0x9F, 0xC9, 0xCF, 0x93, 0xCC, 0xF3, 0x99, 0x9C, 0xC9, 0x99, 0x92, 0x92, 0x9F, 0x99, 
  0xFF, 0xE7, 0xCF, 0xF3, 0xF3, 0xF3, 0xFF, 0xC4, 0xFF, 0xF3, 0xF3, 0x89, 0xC9, 0xC3, 0xE1, 0xFF, 
  }, 
// Row 6
 { 
  0xFF, 0xB3, 0x8C, 0xE3, 0xE3, 0xC1, 0xC1, 0xF3, 0x8C, 0xCC, 0xB3, 0x99, 0xF3, 0xC7, 0xCC, 0xE1, 
  0x8F, 0xF8, 0xC0, 0xFF, 0xF2, 0xE3, 0xC0, 0xE1, 0xF3, 0xE1, 0xF3, 0xE7, 0x80, 0xED, 0x80, 0xF3, 
  0xFF, 0xFF, 0xFF, 0xC9, 0x83, 0xCC, 0x99, 0xFF, 0xE7, 0xE7, 0xCC, 0xE7, 0xE7, 0xFF, 0xE7, 0x9F, 
  0x8C, 0xE7, 0x99, 0x99, 0xF9, 0x99, 0x99, 0xE7, 0x99, 0xF3, 0xE7, 0xE7, 0xE7, 0x81, 0xE7, 0xFF, 
  0x9F, 0x99, 0xCC, 0xCC, 0xC9, 0xCE, 0xCF, 0xCC, 0x99, 0xE7, 0x99, 0xCC, 0xCC, 0x9C, 0x9C, 0xC9, 
  0xCF, 0xC3, 0xCC, 0x99, 0xE7, 0x99, 0xC3, 0x88, 0xC9, 0xE7, 0xCC, 0xCF, 0xFC, 0xF3, 0xFF, 0xFF, 
  0xFF, 0x99, 0xCC, 0x99, 0x99, 0x9F, 0xCF, 0xC1, 0xCC, 0xE7, 0x99, 0xC9, 0xE7, 0x94, 0x99, 0x99, 
  0xC1, 0xC1, 0xCF, 0xF9, 0xE5, 0x99, 0xC3, 0x80, 0xC9, 0xC1, 0xCD, 0xE7, 0xF3, 0xE7, 0xFF, 0x9C, 
  0xF3, 0x99, 0x9F, 0xCC, 0x99, 0x99, 0x99, 0xC3, 0xCF, 0x9F, 0x9F, 0xE7, 0xF3, 0xE7, 0x9C, 0x81, 
  0xCF, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xC1, 0xE1, 0x99, 0xC0, 0x8C, 0x81, 0x98, 0xF3, 
  0x99, 0xE7, 0x99, 0x99, 0x99, 0x91, 0xC0, 0xC1, 0x99, 0x9F, 0xF9, 0xCC, 0xC8, 0xF3, 0xE6, 0x99, 
  0xBB, 0xAA, 0xC4, 0xF3, 0xF3, 0xF3, 0xE4, 0xE4, 0xF3, 0xE4, 0xE4, 0xE4, 0xFF, 0xFF, 0xFF, 0xF3, 
  0xFF, 0xFF, 0xF3, 0xF3, 0xFF, 0xF3, 0xF3, 0xE4, 0xFF, 0xE4, 0xFF, 0xE4, 0xE4, 0xFF, 0xE4, 0xFF, 
  0xFF, 0xF3, 0xE4, 0xFF, 0xFF, 0xF3, 0xE4, 0xE4, 0xF3, 0xFF, 0xF3, 0x80, 0x80, 0x87, 0xF8, 0xFF, 
  0x91, 0x83, 0x9F, 0xC9, 0x99, 0x93, 0xC1, 0xF3, 0xC3, 0xC9, 0xC9, 0x99, 0xC0, 0xC0, 0xCF, 0x99, 
  0x81, 0xFF, 0xFF, 0xFF, 0xF3, 0x93, 0xE7, 0x91, 0xFF, 0xFF, 0xFF, 0xC9, 0xFF, 0xFF, 0xE1, 0xFF, 
  }, 
// Row 7
 { 
  0xFF, 0xBF, 0x80, 0xF7, 0xF7, 0xE3, 0xE3, 0xFF, 0x80, 0xE1, 0x9E, 0x99, 0xC0, 0x87, 0x8C, 0xD2, 
  0xBF, 0xFE, 0xE1, 0xCC, 0xF2, 0x99, 0xC0, 0xF3, 0xF3, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xE7, 0xFF, 0xC9, 0xE7, 0x9C, 0xC4, 0xFF, 0xF3, 0xCF, 0xFF, 0xFF, 0xE7, 0xFF, 0xE7, 0xBF, 
  0xC1, 0x81, 0x81, 0xC3, 0xF0, 0xC3, 0xC3, 0xE7, 0xC3, 0xC7, 0xE7, 0xE7, 0xF3, 0xFF, 0xCF, 0xE7, 
  0xC3, 0x99, 0x81, 0xE1, 0x83, 0x80, 0x87, 0xE0, 0x99, 0xC3, 0xC3, 0x8C, 0x80, 0x9C, 0x9C, 0xE3, 
  0x87, 0xF1, 0x8C, 0xC3, 0xC3, 0x81, 0xE7, 0x9C, 0x9C, 0xC3, 0x80, 0xC3, 0xFE, 0xC3, 0xFF, 0xFF, 
  0xFF, 0xC4, 0x91, 0xC3, 0xC4, 0xC3, 0x87, 0xF9, 0x8C, 0xC3, 0x99, 0x8C, 0xC3, 0x9C, 0x99, 0xC3, 
  0xCF, 0xF9, 0x87, 0x83, 0xF3, 0xC4, 0xE7, 0xC9, 0x9C, 0xF9, 0x81, 0xF1, 0xF3, 0x8F, 0xFF, 0x80, 
  0xF9, 0xC0, 0xC3, 0xE0, 0xC0, 0xC0, 0xC0, 0xF9, 0xE1, 0xC3, 0xC3, 0xC3, 0xE1, 0xC3, 0x9C, 0x99, 
  0x81, 0xC0, 0x98, 0xC3, 0xC3, 0xC3, 0xC0, 0xC0, 0xF9, 0xF3, 0xC3, 0xF3, 0x81, 0xE7, 0x9C, 0x93, 
  0xC0, 0xC3, 0xC3, 0xC0, 0x99, 0x99, 0xFF, 0xFF, 0xC3, 0xFF, 0xFF, 0x99, 0x98, 0xF3, 0xFF, 0xFF, 
  0xEE, 0xD5, 0x92, 0xF3, 0xF3, 0xF3, 0xE4, 0xE4, 0xF3, 0xE4, 0xE4, 0xE4, 0xFF, 0xFF, 0xFF, 0xF3, 
  0xFF, 0xFF, 0xF3, 0xF3, 0xFF, 0xF3, 0xF3, 0xE4, 0xFF, 0xE4, 0xFF, 0xE4, 0xE4, 0xFF, 0xE4, 0xFF, 
  0xFF, 0xF3, 0xE4, 0xFF, 0xFF, 0xF3, 0xE4, 0xE4, 0xF3, 0xFF, 0xF3, 0x80, 0x80, 0x87, 0xF8, 0xFF, 
  0xC4, 0x9F, 0x9F, 0xC9, 0x81, 0xC7, 0xCF, 0xF3, 0xE7, 0xE3, 0x88, 0xC3, 0xFF, 0xCF, 0xE3, 0x99, 
  0xFF, 0x81, 0x81, 0x81, 0xF3, 0x93, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xE1, 0xFF, 0xFF, 0xFF, 0xFF, 
  }, 
// Row 8
 { 
  0xFF, 0xC0, 0xC0, 0xFF, 0xFF, 0xC1, 0xC1, 0xFF, 0x80, 0xFF, 0x80, 0xC3, 0xF3, 0x8F, 0x9F, 0xB3, 
  0xFF, 0xFF, 0xF3, 0xFF, 0xFF, 0xC3, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0xFF, 0xFF, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0x87, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0xFF, 0xFF, 0xF3, 0xFF, 0xE7, 0x9C, 0xC7, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 
  0xBB, 0xAA, 0x88, 0xF3, 0xF3, 0xF3, 0xE4, 0xE4, 0xF3, 0xE4, 0xE4, 0xE4, 0xFF, 0xFF, 0xFF, 0xF3, 
  0xFF, 0xFF, 0xF3, 0xF3, 0xFF, 0xF3, 0xF3, 0xE4, 0xFF, 0xE4, 0xFF, 0xE4, 0xE4, 0xFF, 0xE4, 0xFF, 
  0xFF, 0xF3, 0xE4, 0xFF, 0xFF, 0xF3, 0xE4, 0xE4, 0xF3, 0xFF, 0xF3, 0x80, 0x80, 0x87, 0xF8, 0xFF, 
  0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF, 
  }, 

};  //  end of screen_font
