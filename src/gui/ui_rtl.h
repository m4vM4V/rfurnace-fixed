#pragma once
#include <imgui.h>
#include <string>

extern bool gEnableRTL;

std::string ReverseRTL(const std::string& utf8);

void ImGuiTextRTL(const char* text);
void ImGuiTextRTLRightAlign(const char* text);
void ImGuiRTLToggler(); // optional debug checkbox
