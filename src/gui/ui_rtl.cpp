#include "ui_rtl.h"
#include <algorithm>
#include <imgui.h>

bool gEnableRTL = false;

// Reverse a UTF-8 string for RTL display
std::string ReverseRTL(const std::string& utf8)
{
    ImVector<ImWchar> buf;
    buf.resize(utf8.size() + 1);

    // Convert UTF-8 to ImWchar array
    int n = ImTextStrFromUtf8(buf.Data, buf.Size, utf8.c_str(), utf8.c_str() + utf8.size());
    buf.resize(n);

    // Convert back to UTF-8 in reverse order
    std::string out;
    char tmp[8];
    for (int i = buf.Size - 1; i >= 0; --i)
        out += ImTextCharToUtf8(tmp, buf[i]);

    return out;
}

// Draw text respecting RTL flag
void ImGuiTextRTL(const char* text)
{
    if (!gEnableRTL)
        ImGui::TextUnformatted(text);
    else
        ImGui::TextUnformatted(ReverseRTL(text).c_str());
}

// Draw right-aligned text respecting RTL flag
void ImGuiTextRTLRightAlign(const char* text)
{
    ImVec2 size = ImGui::CalcTextSize(text);
    float avail = ImGui::GetContentRegionAvail().x;
    ImGui::SetCursorPosX(avail - size.x);
    ImGuiTextRTL(text);
}

// Optional debug toggle
void ImGuiRTLToggler()
{
    ImGui::Checkbox("Enable RTL text rendering", &gEnableRTL);
}
