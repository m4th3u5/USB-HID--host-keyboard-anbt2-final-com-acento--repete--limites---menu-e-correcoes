//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32_ub_font.h"

//--------------------------------------------------------------
// PixelFontGenerator 1.0
//--------------------------------------------------------------






















const uint16_t Arial_11x20_Table [] = {
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [ ]
0x0000,0x0000,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [!]
0x0000,0x0000,0x1B00,0x1B00,0x1B00,0x1B00,0x1B00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = ["]
0x0000,0x0000,0x1980,0x1980,0x1980,0x1980,0x7FC0,0x7FC0,0x1980,0x3300,0x7FC0,0x7FC0,0x3300,0x3300,0x3300,0x3300,0x0000,0x0000,0x0000,0x0000, // Ascii = [#]
0x0000,0x0000,0x1E00,0x3F00,0x7580,0x6580,0x7400,0x3C00,0x1E00,0x0700,0x0580,0x6580,0x6580,0x7580,0x3F00,0x1E00,0x0400,0x0400,0x0000,0x0000, // Ascii = [$]
0x0000,0x0000,0x7000,0xD800,0xD840,0xD8C0,0xD980,0x7300,0x0600,0x0C00,0x1B80,0x36C0,0x66C0,0x46C0,0x06C0,0x0380,0x0000,0x0000,0x0000,0x0000, // Ascii = [%]
0x0000,0x0000,0x1E00,0x3F00,0x3300,0x3300,0x3300,0x1E00,0x0C00,0x3CC0,0x66C0,0x6380,0x6180,0x6380,0x3EC0,0x1C80,0x0000,0x0000,0x0000,0x0000, // Ascii = [&]
0x0000,0x0000,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [']
0x0000,0x0000,0x0080,0x0100,0x0300,0x0600,0x0600,0x0400,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0400,0x0600,0x0600,0x0300,0x0100,0x0080, // Ascii = [(]
0x0000,0x0000,0x2000,0x1000,0x1800,0x0C00,0x0C00,0x0400,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0400,0x0C00,0x0C00,0x1800,0x1000,0x2000, // Ascii = [)]
0x0000,0x0000,0x0C00,0x2D00,0x3F00,0x1E00,0x3300,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [*]
0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0C00,0x0C00,0xFFC0,0xFFC0,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [+]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0400,0x0400,0x0800,0x0000, // Ascii = [,]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x1E00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [-]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [.]
0x0000,0x0000,0x0300,0x0300,0x0300,0x0600,0x0600,0x0600,0x0600,0x0C00,0x0C00,0x0C00,0x0C00,0x1800,0x1800,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii = [/]
0x0000,0x0000,0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6D80,0x6D80,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [0]
0x0000,0x0000,0x0600,0x0E00,0x1E00,0x3600,0x2600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [1]
0x0000,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6180,0x0180,0x0300,0x0600,0x0C00,0x1800,0x3000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [2]
0x0000,0x0000,0x1C00,0x3E00,0x6300,0x6300,0x0300,0x0E00,0x0E00,0x0300,0x0180,0x0180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [3]
0x0000,0x0000,0x0600,0x0E00,0x0E00,0x1E00,0x1E00,0x1600,0x3600,0x3600,0x6600,0x7F80,0x7F80,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [4]
0x0000,0x0000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x6E00,0x7F00,0x6380,0x0180,0x0180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [5]
0x0000,0x0000,0x1E00,0x3F00,0x3380,0x6180,0x6000,0x6E00,0x7F00,0x7380,0x6180,0x6180,0x6180,0x3380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [6]
0x0000,0x0000,0x7F80,0x7F80,0x0180,0x0300,0x0300,0x0600,0x0600,0x0C00,0x0C00,0x0C00,0x0800,0x1800,0x1800,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii = [7]
0x0000,0x0000,0x1E00,0x3F00,0x6380,0x6180,0x6180,0x2100,0x1E00,0x3F00,0x6180,0x6180,0x6180,0x6180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [8]
0x0000,0x0000,0x1E00,0x3F00,0x7300,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0180,0x6180,0x7300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [9]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [:]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0400,0x0400,0x0800,0x0000, // Ascii = [;]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0080,0x0380,0x0E00,0x3800,0x6000,0x3800,0x0E00,0x0380,0x0080,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [<]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x7F80,0x7F80,0x0000,0x0000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [=]
0x0000,0x0000,0x0000,0x0000,0x0000,0x4000,0x7000,0x1C00,0x0700,0x0180,0x0700,0x1C00,0x7000,0x4000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [>]
0x0000,0x0000,0x1F00,0x3F80,0x71C0,0x60C0,0x00C0,0x01C0,0x0380,0x0700,0x0E00,0x0C00,0x0C00,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [?]
0x0000,0x0000,0x1E00,0x3F00,0x3180,0x7180,0x6380,0x6F80,0x6D80,0x6D80,0x6F80,0x6780,0x6000,0x3200,0x3E00,0x1C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [@]
0x0000,0x0000,0x0E00,0x0E00,0x1B00,0x1B00,0x1B00,0x1B00,0x3180,0x3180,0x3F80,0x3F80,0x3180,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [A]
0x0000,0x0000,0x7C00,0x7E00,0x6300,0x6300,0x6300,0x6300,0x7E00,0x7E00,0x6300,0x6180,0x6180,0x6380,0x7F00,0x7E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [B]
0x0000,0x0000,0x1E00,0x3F00,0x3180,0x6180,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6180,0x3180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [C]
0x0000,0x0000,0x7C00,0x7F00,0x6300,0x6380,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6300,0x6300,0x7E00,0x7C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [D]
0x0000,0x0000,0x7F80,0x7F80,0x6000,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [E]
0x0000,0x0000,0x7F80,0x7F80,0x6000,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000, // Ascii = [F]
0x0000,0x0000,0x1E00,0x3F00,0x3180,0x6180,0x6000,0x6000,0x6000,0x6380,0x6380,0x6180,0x6180,0x3180,0x3F80,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [G]
0x0000,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x7F80,0x7F80,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [H]
0x0000,0x0000,0x3F00,0x3F00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x3F00,0x3F00,0x0000,0x0000,0x0000,0x0000, // Ascii = [I]
0x0000,0x0000,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [J]
0x0000,0x0000,0x60C0,0x6180,0x6300,0x6600,0x6600,0x6C00,0x7800,0x7C00,0x6600,0x6600,0x6300,0x6180,0x6180,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [K]
0x0000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [L]
0x0000,0x0000,0x71C0,0x71C0,0x7BC0,0x7AC0,0x6AC0,0x6AC0,0x6EC0,0x64C0,0x60C0,0x60C0,0x60C0,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [M]
0x0000,0x0000,0x7180,0x7180,0x7980,0x7980,0x7980,0x6D80,0x6D80,0x6D80,0x6580,0x6780,0x6780,0x6780,0x6380,0x6380,0x0000,0x0000,0x0000,0x0000, // Ascii = [N]
0x0000,0x0000,0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [O]
0x0000,0x0000,0x7E00,0x7F00,0x6380,0x6180,0x6180,0x6180,0x6380,0x7F00,0x7E00,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000, // Ascii = [P]
0x0000,0x0000,0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6580,0x6780,0x3300,0x3F80,0x1E40,0x0000,0x0000,0x0000,0x0000, // Ascii = [Q]
0x0000,0x0000,0x7E00,0x7F00,0x6380,0x6180,0x6180,0x6380,0x7F00,0x7E00,0x6600,0x6300,0x6300,0x6180,0x6180,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [R]
0x0000,0x0000,0x0E00,0x1F00,0x3180,0x3180,0x3000,0x3800,0x1E00,0x0700,0x0380,0x6180,0x6180,0x3180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [S]
0x0000,0x0000,0xFFC0,0xFFC0,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [T]
0x0000,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [U]
0x0000,0x0000,0x60C0,0x60C0,0x60C0,0x3180,0x3180,0x3180,0x1B00,0x1B00,0x1B00,0x1B00,0x0E00,0x0E00,0x0E00,0x0400,0x0000,0x0000,0x0000,0x0000, // Ascii = [V]
0x0000,0x0000,0xC0C0,0xC0C0,0xC0C0,0xC0C0,0xC0C0,0xCCC0,0x4C80,0x4C80,0x5E80,0x5280,0x5280,0x7380,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [W]
0x0000,0x0000,0xC0C0,0x6080,0x6180,0x3300,0x3B00,0x1E00,0x0C00,0x0C00,0x1E00,0x1F00,0x3B00,0x7180,0x6180,0xC0C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [X]
0x0000,0x0000,0xC0C0,0x6180,0x6180,0x3300,0x3300,0x1E00,0x1E00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [Y]
0x0000,0x0000,0x3F80,0x3F80,0x0180,0x0300,0x0300,0x0600,0x0C00,0x0C00,0x1800,0x1800,0x3000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [Z]
0x0000,0x0000,0x0F00,0x0F00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0F00,0x0F00, // Ascii = [[]
0x0000,0x0000,0x1800,0x1800,0x1800,0x0C00,0x0C00,0x0C00,0x0C00,0x0600,0x0600,0x0600,0x0600,0x0300,0x0300,0x0300,0x0000,0x0000,0x0000,0x0000, // Ascii = [\]
0x0000,0x0000,0x1E00,0x1E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x1E00,0x1E00, // Ascii = []]
0x0000,0x0000,0x0C00,0x0C00,0x1E00,0x1200,0x3300,0x3300,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [^]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFE0,0x0000,0x0000, // Ascii = [_]
0x0000,0x0000,0x3800,0x1800,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [`]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1F00,0x3F80,0x6180,0x0180,0x1F80,0x3F80,0x6180,0x6380,0x7F80,0x38C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [a]
0x0000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6E00,0x7F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x7F00,0x6E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [b]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6000,0x6000,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [c]
0x0000,0x0000,0x0180,0x0180,0x0180,0x0180,0x1D80,0x3F80,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0000,0x0000,0x0000,0x0000, // Ascii = [d]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F00,0x7300,0x6180,0x7F80,0x7F80,0x6000,0x7180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [e]
0x0000,0x0000,0x07C0,0x0FC0,0x0C00,0x0C00,0x7F80,0x7F80,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [f]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1D80,0x3F80,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0180,0x6380,0x7F00,0x3E00, // Ascii = [g]
0x0000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6F00,0x7F80,0x7180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [h]
0x0000,0x0000,0x0600,0x0600,0x0000,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [i]
0x0000,0x0000,0x0600,0x0600,0x0000,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x4600,0x7E00,0x3C00, // Ascii = [j]
0x0000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6180,0x6300,0x6600,0x6C00,0x7C00,0x7600,0x6300,0x6300,0x6180,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [k]
0x0000,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [l]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xDD80,0xFFC0,0xCEC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0x0000,0x0000,0x0000,0x0000, // Ascii = [m]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6F00,0x7F80,0x7180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [n]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [o]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6E00,0x7F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x7F00,0x6E00,0x6000,0x6000,0x6000,0x6000, // Ascii = [p]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1D80,0x3F80,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0180,0x0180,0x0180,0x0180, // Ascii = [q]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6700,0x3F80,0x3900,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x0000,0x0000,0x0000,0x0000, // Ascii = [r]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F80,0x6180,0x6000,0x7F00,0x3F80,0x0180,0x6180,0x7F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [s]
0x0000,0x0000,0x0000,0x0800,0x1800,0x1800,0x7F00,0x7F00,0x1800,0x1800,0x1800,0x1800,0x1800,0x1800,0x1F80,0x0F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [t]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6380,0x7F80,0x3D80,0x0000,0x0000,0x0000,0x0000, // Ascii = [u]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x60C0,0x3180,0x3180,0x3180,0x1B00,0x1B00,0x1B00,0x0E00,0x0E00,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [v]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xDD80,0xDD80,0xDD80,0x5500,0x5500,0x5500,0x7700,0x7700,0x2200,0x2200,0x0000,0x0000,0x0000,0x0000, // Ascii = [w]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6180,0x3300,0x3300,0x1E00,0x0C00,0x0C00,0x1E00,0x3300,0x3300,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [x]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6180,0x6180,0x3180,0x3300,0x3300,0x1B00,0x1B00,0x1B00,0x0E00,0x0E00,0x0E00,0x1C00,0x7C00,0x7000, // Ascii = [y]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x7FC0,0x7FC0,0x0180,0x0300,0x0600,0x0C00,0x1800,0x3000,0x7FC0,0x7FC0,0x0000,0x0000,0x0000,0x0000, // Ascii = [z]
0x0000,0x0000,0x0380,0x0780,0x0600,0x0600,0x0600,0x0600,0x0600,0x0E00,0x1C00,0x1C00,0x0E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0780,0x0380, // Ascii = [{]
0x0000,0x0000,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600, // Ascii = [|]
0x0000,0x0000,0x3800,0x3C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0E00,0x0700,0x0700,0x0E00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x3C00,0x3800, // Ascii = [}]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3880,0x7F80,0x4700,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [~]
0x0000,0x0000,0x0000,0x0000,0xF800,0xD800,0xD800,0xD800,0xD800,0xD800,0xD800,0xD800,0xD800,0xD800,0xD800,0xF800,0x0000,0x0000,0x0000,0x0000, // Ascii:127 = []
0x0000,0x0000,0x0000,0x0000,0x0000,0x1800,0x3C00,0x7400,0x6000,0xF800,0x6000,0xF800,0x6000,0x7400,0x3C00,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii:128 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:129 = []
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x6000,0x2000,0x2000,0x4000,0x0000, // Ascii:130 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0E00,0x1E00,0x1800,0x3C00,0x3C00,0x1800,0x1800,0x3000,0x3000,0x3000,0x3000,0x3000,0xF000,0xE000,0x0000, // Ascii:131 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6C00,0x6C00,0x2400,0x2400,0x4800,0x0000, // Ascii:132 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6660,0x6660,0x0000,0x0000,0x0000,0x0000, // Ascii:133 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x3000,0x3000,0x3000,0xFC00,0xFC00,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x0000, // Ascii:134 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x3000,0x3000,0x3000,0xFC00,0xFC00,0x3000,0x3000,0x3000,0x3000,0xFC00,0xFC00,0x3000,0x3000,0x3000,0x0000, // Ascii:135 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x7000,0xD800,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:136 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6200,0x9400,0x9400,0x9400,0x9800,0x6B30,0x0CC8,0x14C8,0x14C8,0x14C8,0x2330,0x0000,0x0000,0x0000,0x0000, // Ascii:137 = [�]
0x0000,0x0000,0x3600,0x1C00,0x0000,0x3E00,0x7F00,0x6300,0x6300,0x7800,0x3E00,0x0700,0x6300,0x6300,0x7F00,0x3E00,0x0000,0x0000,0x0000,0x0000, // Ascii:138 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1000,0x3000,0x2000,0x6000,0x2000,0x3000,0x1000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:139 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1BF0,0x3FF0,0x7700,0x6300,0x63F0,0x63F0,0x6300,0x6300,0x7700,0x3FF0,0x1BF0,0x0000,0x0000,0x0000,0x0000, // Ascii:140 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:141 = []
0x0000,0x0000,0x6C00,0x3800,0x0000,0xFE00,0xFE00,0x0600,0x0C00,0x1800,0x3000,0x3000,0x6000,0xC000,0xFE00,0xFE00,0x0000,0x0000,0x0000,0x0000, // Ascii:142 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:143 = []
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:144 = []
0x0000,0x0000,0x0000,0x0000,0x0000,0x2000,0x4000,0x4000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:145 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x6000,0x2000,0x2000,0x4000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:146 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x2400,0x4800,0x4800,0x6C00,0x6C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:147 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6C00,0x6C00,0x2400,0x2400,0x4800,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:148 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0xF000,0xF000,0xF000,0x6000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:149 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFE00,0xFE00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:150 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFF8,0xFFF8,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:151 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0xD000,0xB000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:152 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x7DB0,0x11B0,0x11B0,0x1150,0x1150,0x1150,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:153 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6C00,0x3800,0x0000,0x3800,0x7C00,0x6400,0x7000,0x1C00,0x4C00,0x7C00,0x3800,0x0000,0x0000,0x0000,0x0000, // Ascii:154 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x4000,0x6000,0x2000,0x3000,0x2000,0x6000,0x4000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:155 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3980,0x3FC0,0x6660,0x67E0,0x67E0,0x6600,0x3FE0,0x39C0,0x0000,0x0000,0x0000,0x0000, // Ascii:156 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:157 = []
0x0000,0x0000,0x0000,0x0000,0x0000,0x3600,0x1C00,0x0000,0xFC00,0xFC00,0x1800,0x3000,0x3000,0x6000,0xFC00,0xFC00,0x0000,0x0000,0x0000,0x0000, // Ascii:158 = [�]
0x0000,0x0000,0x6C00,0x6C00,0x0000,0xC300,0x6600,0x6600,0x3C00,0x3C00,0x1800,0x1800,0x1800,0x1800,0x1800,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii:159 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:160 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x6000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000, // Ascii:161 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0800,0x0800,0x1000,0x7800,0x7C00,0xDC00,0xD000,0xEC00,0xEC00,0x7800,0x7800,0x4000,0x4000,0x4000,0x0000, // Ascii:162 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x3C00,0x7C00,0x6600,0x6600,0x6000,0xF800,0xF800,0x3000,0x7200,0xFE00,0x8E00,0x0000,0x0000,0x0000,0x0000, // Ascii:163 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x4200,0xFF00,0x7E00,0x6600,0x6600,0x6600,0x7E00,0xFF00,0x4200,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:164 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0xC300,0x6600,0x6600,0x3C00,0x3C00,0xFF00,0xFF00,0x1800,0xFF00,0xFF00,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii:165 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000, // Ascii:166 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x7800,0xFC00,0xC600,0xE000,0x7800,0xDC00,0xC600,0xC600,0x7600,0x3C00,0x0E00,0xC600,0x7E00,0x3C00,0x0000, // Ascii:167 = [�]
0x0000,0x0000,0x0000,0x0000,0xD800,0xD800,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:168 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x2100,0x4C80,0x9240,0x9040,0x9040,0x9040,0x9240,0x4C80,0x2100,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii:169 = [�]
0x0000,0x0000,0x0000,0x0000,0xE000,0x1000,0x7000,0x9000,0x9000,0xF000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:170 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x2400,0x6C00,0x4800,0xD800,0x4800,0x6C00,0x2400,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:171 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x7E00,0x7E00,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:172 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF000,0xF000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:173 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x2100,0x5E80,0x9240,0x9240,0x9C40,0x9440,0x9440,0x5280,0x2100,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii:174 = [�]
0x0000,0x0000,0xFF00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:175 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x7000,0x8800,0x8800,0x8800,0x7000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:176 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1800,0x1800,0x1800,0xFF00,0xFF00,0x1800,0x1800,0x1800,0x0000,0xFF00,0xFF00,0x0000,0x0000,0x0000,0x0000, // Ascii:177 = [�]
0x0000,0x0000,0x0000,0x0000,0x6000,0x9000,0x1000,0x2000,0x4000,0xF000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:178 = [�]
0x0000,0x0000,0x0000,0x0000,0x7000,0x9000,0x2000,0x1000,0x9000,0x6000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:179 = [�]
0x0300,0x0600,0x0c00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:180 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6300,0x6300,0x6300,0x6300,0x6300,0x6300,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x0000, // Ascii:181 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x7E00,0xFE00,0xEC00,0xEC00,0xEC00,0xEC00,0x6C00,0x6C00,0x6C00,0x6C00,0x6C00,0x6C00,0x6C00,0x6C00,0x0000, // Ascii:182 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:183 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x2000,0xE000,0x0000, // Ascii:184 = [�]
0x0000,0x0000,0x0000,0x0000,0x4000,0xC000,0x4000,0x4000,0x4000,0x4000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:185 = [�]
0x0000,0x0000,0x0000,0x0000,0x6000,0x9000,0x9000,0x9000,0x9000,0x6000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:186 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x4800,0x6C00,0x2400,0x3600,0x2400,0x6C00,0x4800,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:187 = [�]
0x0000,0x0000,0x0000,0x0000,0x4000,0xC100,0x4200,0x4200,0x4400,0x4400,0x0840,0x08C0,0x08C0,0x1140,0x11E0,0x2040,0x0000,0x0000,0x0000,0x0000, // Ascii:188 = [�]
0x0000,0x0000,0x0000,0x0000,0x4000,0xC100,0x4200,0x4200,0x4400,0x4400,0x08C0,0x0920,0x0820,0x1040,0x1080,0x21E0,0x0000,0x0000,0x0000,0x0000, // Ascii:189 = [�]
0x0000,0x0000,0x0000,0x0000,0x7000,0x9080,0x2100,0x1100,0x9200,0x6200,0x0440,0x04C0,0x04C0,0x0940,0x09E0,0x1040,0x0000,0x0000,0x0000,0x0000, // Ascii:190 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1800,0x1800,0x0000,0x1800,0x1800,0x3000,0x7000,0x6600,0x6600,0x7E00,0x3C00,0x0000, // Ascii:191 = [�]
0x3000,0x1800,0x0C00,0x0000,0x0E00,0x0E00,0x1B00,0x1B00,0x3180,0x3180,0x3F80,0x3F80,0x3180,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0300,0x0600,0x0c00,0x0000,0x0E00,0x0E00,0x1B00,0x1B00,0x3180,0x3180,0x3F80,0x3F80,0x3180,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0E00,0x1B00,0x3180,0x0000,0x0E00,0x0E00,0x1B00,0x1B00,0x3180,0x3180,0x3F80,0x3F80,0x3180,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x3880,0x7F80,0x4700,0x0000,0x0E00,0x0E00,0x1B00,0x1B00,0x3180,0x3180,0x3F80,0x3F80,0x3180,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x3600,0x3600,0x0000,0x1C00,0x1C00,0x1C00,0x3600,0x3600,0x3600,0x6300,0x7F00,0x7F00,0xC180,0xC180,0x0000,0x0000,0x0000,0x0000, // Ascii:196 = [�]
0x0000,0x1C00,0x1400,0x1C00,0x0000,0x1C00,0x1C00,0x1C00,0x3600,0x3600,0x3600,0x6300,0x7F00,0x7F00,0xC180,0xC180,0x0000,0x0000,0x0000,0x0000, // Ascii:197 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1FF0,0x1FF0,0x1B00,0x3B00,0x33F0,0x33F0,0x7F00,0x7F00,0x6300,0xE3F0,0xC3F0,0x0000,0x0000,0x0000,0x0000, // Ascii:198 = [�]
0x0000,0x0000,0x1E00,0x3F00,0x3180,0x6180,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6180,0x3180,0x3F00,0x1E00,0x0400,0x0200,0x0C00,0x0000, // Ascii = [�]
0x3000,0x1800,0x0C00,0x0000,0x7F80,0x7F80,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0300,0x0600,0x0c00,0x0000,0x7F80,0x7F80,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0C00,0x1E00,0x3300,0x0000,0x7F80,0x7F80,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x3600,0x3600,0x0000,0x7F00,0x7F00,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x0000,0x0000,0x0000,0x0000, // Ascii:203 = [�]
0x3000,0x1800,0x0C00,0x0000,0x3F00,0x3F00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x3F00,0x3F00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0300,0x0600,0x0c00,0x0000,0x3F00,0x3F00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x3F00,0x3F00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0C00,0x1E00,0x3300,0x0000,0x3F00,0x3F00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x3F00,0x3F00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0xB000,0xB000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000, // Ascii:207 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x7C00,0x7E00,0x6700,0x6300,0xFB00,0xFB00,0x6300,0x6300,0x6700,0x7E00,0x7C00,0x0000,0x0000,0x0000,0x0000, // Ascii:208 = [�]
0x0000,0x0000,0x3400,0x2C00,0x0000,0x6300,0x7300,0x7300,0x7300,0x7B00,0x6B00,0x6F00,0x6F00,0x6700,0x6700,0x6300,0x0000,0x0000,0x0000,0x0000, // Ascii:209 = [�]
0x3000,0x1800,0x0C00,0x0000,0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0300,0x0600,0x0c00,0x0000,0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0C00,0x1E00,0x3300,0x0000,0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x3880,0x7F80,0x4700,0x0000,0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x3600,0x3600,0x0000,0x1E00,0x3F00,0x3380,0x6180,0x6180,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii:214 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6600,0x3C00,0x1800,0x3C00,0x6600,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:215 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1E80,0x3F80,0x7300,0x6380,0x6780,0x6D80,0x7980,0x7180,0x3380,0x7F00,0x5E00,0x0000,0x0000,0x0000,0x0000, // Ascii:216 = [�]
0x3000,0x1800,0x0C00,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0300,0x0600,0x0c00,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0C00,0x1E00,0x3300,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x3600,0x3600,0x0000,0x6300,0x6300,0x6300,0x6300,0x6300,0x6300,0x6300,0x6300,0x6300,0x3F00,0x1C00,0x0000,0x0000,0x0000,0x0000, // Ascii:220 = [�]
0x0000,0x0000,0x1800,0x3000,0x0000,0xC300,0x6600,0x6600,0x3C00,0x3C00,0x1800,0x1800,0x1800,0x1800,0x1800,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii:221 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x6000,0x7E00,0x7F00,0x6300,0x6300,0x6300,0x7F00,0x7E00,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000, // Ascii:222 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x3C00,0x7E00,0x6600,0x6600,0x6C00,0x6C00,0x6600,0x6300,0x6B00,0x6F00,0x6600,0x0000,0x0000,0x0000,0x0000, // Ascii:223 = [�]
0x0000,0x0000,0x3000,0x1800,0x0C00,0x0000,0x1F00,0x3F80,0x6180,0x0180,0x1F80,0x3F80,0x6180,0x6380,0x7F80,0x38C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0300,0x0600,0x0c00,0x0000,0x1F00,0x3F80,0x6180,0x0180,0x1F80,0x3F80,0x6180,0x6380,0x7F80,0x38C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0C00,0x1E00,0x1200,0x3300,0x0000,0x1F00,0x3F80,0x6180,0x0180,0x1F80,0x3F80,0x6180,0x6380,0x7F80,0x38C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x3880,0x7F80,0x4700,0x0000,0x1F00,0x3F80,0x6180,0x0180,0x1F80,0x3F80,0x6180,0x6380,0x7F80,0x38C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0xD800,0xD800,0x0000,0x7800,0xFC00,0xCC00,0x3C00,0xFC00,0xCC00,0xFC00,0x6C00,0x0000,0x0000,0x0000,0x0000, // Ascii:228 = [�]
0x0000,0x0000,0x0000,0x0000,0x7000,0x5000,0x7000,0x0000,0x7800,0xFC00,0xCC00,0x3C00,0xFC00,0xCC00,0xFC00,0x6C00,0x0000,0x0000,0x0000,0x0000, // Ascii:229 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3DC0,0x7FE0,0x6660,0x1FE0,0x7FE0,0x6600,0x7FE0,0x39C0,0x0000,0x0000,0x0000,0x0000, // Ascii:230 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6000,0x6000,0x6180,0x7380,0x3F00,0x1E00,0x0400,0x0200,0x0C00,0x0000, // Ascii = [�]
0x0000,0x0000,0x3000,0x1800,0x0C00,0x0000,0x1E00,0x3F00,0x7300,0x6180,0x7F80,0x7F80,0x6000,0x7180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0300,0x0600,0x0c00,0x0000,0x1E00,0x3F00,0x7300,0x6180,0x7F80,0x7F80,0x6000,0x7180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0C00,0x1E00,0x1200,0x3300,0x0000,0x1E00,0x3F00,0x7300,0x6180,0x7F80,0x7F80,0x6000,0x7180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6C00,0x6C00,0x0000,0x3800,0x7C00,0x6C00,0x7C00,0x6000,0x6C00,0x7C00,0x3800,0x0000,0x0000,0x0000,0x0000, // Ascii:235 = [�]
0x0000,0x0000,0x3000,0x1800,0x0C00,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0300,0x0600,0x0c00,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0C00,0x1E00,0x1200,0x3300,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0xB000,0xB000,0x0000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000, // Ascii:239 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1C00,0x1C00,0x2C00,0x7C00,0x7E00,0xC600,0xC600,0xC600,0xC600,0x7C00,0x3800,0x0000,0x0000,0x0000,0x0000, // Ascii:240 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x3400,0x2C00,0x0000,0x6C00,0x7E00,0x6600,0x6600,0x6600,0x6600,0x6600,0x6600,0x0000,0x0000,0x0000,0x0000, // Ascii:241 = [�]
0x0000,0x0000,0x3000,0x1800,0x0C00,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0300,0x0600,0x0c00,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0C00,0x1E00,0x1200,0x3300,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x3880,0x7F80,0x4700,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6C00,0x6C00,0x0000,0x3C00,0x3C00,0x6600,0x6600,0x6600,0x6600,0x3C00,0x3C00,0x0000,0x0000,0x0000,0x0000, // Ascii:246 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1800,0x1800,0x0000,0xFF00,0xFF00,0x0000,0x1800,0x1800,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:247 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3E00,0x3C00,0x6600,0x6E00,0x7600,0x6600,0x3C00,0x7C00,0x0000,0x0000,0x0000,0x0000, // Ascii:248 = [�]
0x0000,0x0000,0x3000,0x1800,0x0C00,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6380,0x7F80,0x3D80,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0300,0x0600,0x0c00,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6380,0x7F80,0x3D80,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0C00,0x1E00,0x1200,0x3300,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6380,0x7F80,0x3D80,0x0000,0x0000,0x0000,0x0000, // Ascii = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6C00,0x6C00,0x0000,0x6600,0x6600,0x6600,0x6600,0x6600,0x6600,0x7E00,0x3600,0x0000,0x0000,0x0000,0x0000, // Ascii:252 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x1800,0x3000,0x0000,0xC600,0xC600,0x6C00,0x6C00,0x6C00,0x3800,0x3800,0x3800,0x3000,0xF000,0xE000,0x0000, // Ascii:253 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6000,0x6000,0x6000,0x6C00,0x7E00,0x6600,0x6600,0x6600,0x6600,0x7E00,0x6C00,0x6000,0x6000,0x6000,0x0000, // Ascii:254 = [�]
0x0000,0x0000,0x0000,0x0000,0x0000,0x6C00,0x6C00,0x0000,0xC600,0xC600,0x6C00,0x6C00,0x6C00,0x3800,0x3800,0x3800,0x3000,0xF000,0xE000,0x0000, // Ascii:255 = [�]
};


//--------------------------------------------------------------
// Estrutura da Fonte
//--------------------------------------------------------------
UB_Font Arial_11x20 = {
  Arial_11x20_Table,  //Tabela com os dados
  11,                // Largura do caractere (Pixel)
  20,                // Altura do caractere (Pixel)
};


