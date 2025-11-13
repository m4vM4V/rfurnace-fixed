#include "ui_fonts.h"
#include <imgui.h>

void LoadFonts()
{
    ImGuiIO& io = ImGui::GetIO();

    // Clear existing fonts
    io.Fonts->Clear();

    // Default font
    io.FontDefault = io.Fonts->AddFontDefault();

    // Hebrew font with custom glyph range
    ImFontConfig cfg;
    cfg.MergeMode = true;
    cfg.PixelSnapH = true;

    // ASCII + Hebrew block
    static const ImWchar hebrew_ranges[] = { 0x0020, 0x007E, 0x0590, 0x05FF, 0 };

    io.Fonts->AddFontFromFileTTF("res/fonts/NotoSansHebrew-VariableFont_wdth,wght.ttf", 18.0f, &cfg, hebrew_ranges);

    // Build atlas
    io.Fonts->Build();
}
