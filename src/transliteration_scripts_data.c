
#include "unicode_scripts.h"

typedef struct script_transliteration_rule {
    script_language_t script_language;
    transliterator_index_t index;
} script_transliteration_rule_t;

script_transliteration_rule_t script_transliteration_rules[] = {
    {{SCRIPT_THAANA, ""}, {0, 2}},
    {{SCRIPT_TELUGU, ""}, {2, 1}},
    {{SCRIPT_CYRILLIC, "be"}, {3, 1}},
    {{SCRIPT_CYRILLIC, "bg"}, {4, 1}},
    {{SCRIPT_CYRILLIC, ""}, {5, 1}},
    {{SCRIPT_CYRILLIC, "ru"}, {6, 1}},
    {{SCRIPT_CYRILLIC, "uz"}, {7, 1}},
    {{SCRIPT_CYRILLIC, "kk"}, {8, 1}},
    {{SCRIPT_CYRILLIC, "sr"}, {9, 1}},
    {{SCRIPT_CYRILLIC, "mn"}, {10, 1}},
    {{SCRIPT_CYRILLIC, "mk"}, {11, 1}},
    {{SCRIPT_CYRILLIC, "uk"}, {12, 1}},
    {{SCRIPT_CYRILLIC, "ky"}, {13, 1}},
    {{SCRIPT_HANGUL, ""}, {14, 2}},
    {{SCRIPT_HAN, ""}, {16, 1}},
    {{SCRIPT_ARMENIAN, ""}, {17, 1}},
    {{SCRIPT_TAMIL, ""}, {18, 1}},
    {{SCRIPT_MALAYALAM, ""}, {19, 1}},
    {{SCRIPT_GUJARATI, ""}, {20, 1}},
    {{SCRIPT_LATIN, ""}, {21, 1}},
    {{SCRIPT_GEORGIAN, ""}, {22, 2}},
    {{SCRIPT_DEVANAGARI, ""}, {24, 1}},
    {{SCRIPT_THAI, ""}, {25, 1}},
    {{SCRIPT_GREEK, ""}, {26, 3}},
    {{SCRIPT_KATAKANA, ""}, {29, 2}},
    {{SCRIPT_ORIYA, ""}, {31, 1}},
    {{SCRIPT_HIRAGANA, ""}, {32, 1}},
    {{SCRIPT_ARABIC, "fa"}, {33, 1}},
    {{SCRIPT_ARABIC, ""}, {34, 2}},
    {{SCRIPT_ARABIC, "ps"}, {36, 1}},
    {{SCRIPT_CANADIAN_ABORIGINAL, ""}, {37, 1}},
    {{SCRIPT_BENGALI, ""}, {38, 1}},
    {{SCRIPT_GURMUKHI, ""}, {39, 1}},
    {{SCRIPT_KANNADA, ""}, {40, 1}},
    {{SCRIPT_COMMON, ""}, {41, 1}},
    {{SCRIPT_HEBREW, ""}, {42, 2}}
};

char *script_transliterators[] = {
    "thaana-latin",
    "maldivian-latin-bgn",
    "telugu-latin",
    "belarusian-latin-bgn",
    "bulgarian-latin-bgn",
    "cyrillic-latin",
    "russian-latin-bgn",
    "uzbek-latin-bgn",
    "kazakh-latin-bgn",
    "serbian-latin-bgn",
    "mongolian-latin-bgn",
    "macedonian-latin-bgn",
    "ukrainian-latin-bgn",
    "kirghiz-latin-bgn",
    "hangul-latin",
    "korean-latin-bgn",
    "han-latin",
    "armenian-latin-bgn",
    "tamil-latin",
    "malayam-latin",
    "gujarati-latin",
    "latin-ascii",
    "georgian-latin",
    "georgian-latin-bgn",
    "devanagari-latin",
    "thai-latin",
    "greek-latin",
    "greek-latin-bgn",
    "greek-latin-ungegn",
    "katakana-latin",
    "katakana-latin-bgn",
    "oriya-latin",
    "hiragana-latin",
    "persian-latin-bgn",
    "arabic-latin",
    "arabic-latin-bgn",
    "pashto-latin-bgn",
    "canadianaboriginal-latin",
    "bengali-latin",
    "gurmukhi-latin",
    "kannada-latin",
    "latin-ascii",
    "hebrew-latin",
    "hebrew-latin-bgn"
};

