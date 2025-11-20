void ui_init_fonts()
{
    ImGuiIO& io = ImGui::GetIO();
    ...
    io.Fonts->AddFontFromFileTTF("res/fonts/NotoSansHebrew-VariableFont_wdth,wght.ttf", size, &config, io.Fonts->GetGlyphRangesDefault());
}
