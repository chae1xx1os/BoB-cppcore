#include <iostream>
#include <sstream>
#include "pch.h"
#include "Struct.h"
#include "PrintString.h"

// 줄바꿈과 공백을 처리하여 원하는 형식으로 출력하는 함수
std::wstring FormatOutput(const std::wstring& str) {
    std::wstringstream stream(str);
    std::wstring line;
    std::wstring result;

    bool firstLine = true;

    while (std::getline(stream, line)) {
        std::size_t pos = line.find_first_not_of(L" \t");
        if (pos != std::wstring::npos) {
            if (!firstLine) {
                result += L"\n";  // 줄바꿈 추가
            }
            result += line.substr(pos);
        }
        firstLine = false;
    }
    return result;
}

void PrintWithLabel(const std::wstring& label, const std::wstring& content) {
    std::wcout << label;
    std::wcout << FormatOutput(content) << std::endl;
    std::wcout << std::endl;  // 항목 사이에 빈 줄 추가
}

int main(void)
{
    setlocale(LC_ALL, "korean");

    // ST_BUILD_FILE_INFO 구조체 초기화
    ST_BUILD_FILE_INFO report;
    report.User.nGeneration = 13;
    report.User.strName = TEXT("김태양");
    report.User.strEMail = TEXT("kty1895@naver.com");

    report.HWDesc.strFilePath = core::GetFileName();
    report.HWDesc.strDesc_TrialAndError = core::TCSFromMBS(R"(
        비오비 차세대 보안 리더 양성 프로그램을 기점으로 제 진로를 잡는
        좋은 기회가 될 수 있는거 같습니다!
    )");
    report.HWDesc.strDesc_Impression = core::TCSFromMBS(R"(
        이번 과제를 통해 얻은 것은 실무에서 코드 관리를 어떤식으로 하는지,
        클래스 정의로 리소스 파일 및 헤더 파일까지 생성하며 시간 단축을 어떻게
        효과적으로 할 수 있는지 배울 수 있었습니다!
    )");
    report.HWDesc.strDesc_Suggestions = core::TCSFromMBS(R"(
        멘토님의 구조체나 함수 선언 등 코드 작성하는데 꿀팁을 알고 싶습니다!
        매번 열정적인 수업 정말 감사합니다^^
    )");

    try
    {
        // 사용자 정보 출력
        std::wcout << L"Name=" << report.User.strName << std::endl;
        std::wcout << L"EMail=" << report.User.strEMail << std::endl;

        std::wcout << std::endl << L"[HWDesc]" << std::endl;
        std::wcout << L"FilePath=" << report.HWDesc.strFilePath << std::endl;
        std::wcout << std::endl;
        PrintWithLabel(L"Desc_TrialAndError=", report.HWDesc.strDesc_TrialAndError);
        PrintWithLabel(L"Desc_Impression=", report.HWDesc.strDesc_Impression);
        PrintWithLabel(L"Desc_Suggestions=", report.HWDesc.strDesc_Suggestions);

        // 성공 메시지 출력
        std::wcout << L"You succeeded!" << std::endl;

    }
    catch (const std::exception& e)
    {
        std::wcout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
