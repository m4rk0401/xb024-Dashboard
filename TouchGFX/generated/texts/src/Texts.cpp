/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x56, 0x6f, 0x6c, 0x74, 0x3a, 0x20, 0x2, 0x20, 0x56, 0x0, // @0 "Volt: <> V"
    0x44, 0x61, 0x74, 0x61, 0x3a, 0x20, 0x2, 0x0, // @10 "Data: <>"
    0x44, 0x56, 0x20, 0x45, 0x42, 0x53, 0x20, 0x54, 0x65, 0x73, 0x74, 0x0, // @18 "DV EBS Test"
    0x44, 0x56, 0x20, 0x53, 0x6b, 0x69, 0x64, 0x20, 0x50, 0x61, 0x64, 0x0, // @30 "DV Skid Pad"
    0x46, 0x72, 0x6f, 0x6e, 0x74, 0x20, 0x52, 0x69, 0x67, 0x68, 0x74, 0x0, // @42 "Front Right"
    0x42, 0x72, 0x61, 0x6b, 0x65, 0x20, 0x54, 0x65, 0x73, 0x74, 0x0, // @54 "Brake Test"
    0x2, 0x20, 0x25, 0x0, // @65 "<> %"
    0x42, 0x61, 0x73, 0x65, 0x20, 0x4d, 0x6f, 0x64, 0x65, 0x0, // @69 "Base Mode"
    0x45, 0x56, 0x20, 0x53, 0x63, 0x72, 0x75, 0x74, 0x69, 0x0, // @79 "EV Scruti"
    0x50, 0x72, 0x65, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x0, // @89 "Precharge"
    0x53, 0x70, 0x65, 0x65, 0x64, 0x20, 0x4c, 0x69, 0x6d, 0x0, // @99 "Speed Lim"
    0x42, 0x61, 0x74, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x0, // @109 "Bat Temp"
    0x44, 0x56, 0x20, 0x41, 0x63, 0x63, 0x65, 0x6c, 0x0, // @118 "DV Accel"
    0x44, 0x56, 0x20, 0x41, 0x75, 0x74, 0x6f, 0x58, 0x0, // @127 "DV AutoX"
    0x44, 0x56, 0x20, 0x54, 0x72, 0x61, 0x63, 0x6b, 0x0, // @136 "DV Track"
    0x44, 0x56, 0x20, 0x49, 0x6e, 0x73, 0x70, 0x0, // @145 "DV Insp"
    0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x0, // @153 "Mission"
    0x50, 0x61, 0x72, 0x61, 0x6d, 0x73, 0x0, // @161 "Params"
    0x50, 0x6f, 0x77, 0x65, 0x72, 0x0, // @168 "Power"
    0x45, 0x6e, 0x64, 0x75, 0x0, // @174 "Endu"
    0x4d, 0x61, 0x69, 0x6e, 0x0, // @179 "Main"
    0x30, 0x30, 0x30, 0x0, // @184 "000"
    0x36, 0x30, 0x30, 0x0, // @188 "600"
    0x53, 0x44, 0x43, 0x0, // @192 "SDC"
    0x53, 0x6f, 0x43, 0x0, // @196 "SoC"
    0x44, 0x56, 0x0 // @200 "DV"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
