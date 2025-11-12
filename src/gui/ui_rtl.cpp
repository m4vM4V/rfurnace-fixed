#include "imgui.h"
#include <string>
#include <algorithm>

std::string ReverseRTL(const std::string& utf8)
{
    ImVector<ImWchar> buf;
    ImTextStrFromUtf8(buf, utf8.c_str(), utf8.c_str() + utf8.size());
    std::reverse(buf.begin(), buf.end());

    std::string out;
    char tmp[8];
    for (ImWchar c : buf)
        out += ImTextCharToUtf8(tmp, c);
    return out;
}

void ImGuiTextRTL(const std::string& text)
{
    std::string rtl = ReverseRTL(text);
    ImGui::TextUnformatted(rtl.c_str());
}

void ImGuiTextRTLRightAlign(const std::string& text)
{
    std::string rtl = ReverseRTL(text);
    float textWidth = ImGui::CalcTextSize(rtl.c_str()).x;
    float windowWidth = ImGui::GetWindowContentRegionMax().x - ImGui::GetWindowContentRegionMin().x;

    ImGui::SetCursorPosX(windowWidth - textWidth - ImGui::GetStyle().ItemSpacing.x);
    ImGui::TextUnformatted(rtl.c_str());
}
