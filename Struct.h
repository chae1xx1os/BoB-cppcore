#pragma once

#include "pch.h"
#include <map>
#include <vector>
#include <string>

// Summary 구조체 정의
struct ST_FILE_SUMMARY : public core::IFormatterObject
{
    std::tstring result;
    std::tstring detectName;
    std::tstring engineName;
    std::tstring engineVersion;
    int severity;
    std::tstring sampleName;
    std::tstring sampleExt;
    double totalElapsedTime;
    bool reachedFileLoopLimit;
    bool reachedUrlLoopLimit;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("Result"), result)
            + core::sPair(TEXT("DetectName"), detectName)
            + core::sPair(TEXT("EngineName"), engineName)
            + core::sPair(TEXT("EngineVersion"), engineVersion)
            + core::sPair(TEXT("Severity"), severity)
            + core::sPair(TEXT("SampleName"), sampleName)
            + core::sPair(TEXT("SampleExt"), sampleExt)
            + core::sPair(TEXT("TotalElapsedTime"), totalElapsedTime)
            + core::sPair(TEXT("ReachedFileLoopLimit"), reachedFileLoopLimit)
            + core::sPair(TEXT("ReachedUrlLoopLimit"), reachedUrlLoopLimit)
            ;
    }
};

// FileTarget 구조체 정의
struct ST_FILE_FILE_TARGET : public core::IFormatterObject
{
    std::tstring TargetID;
    std::tstring ParentID;
    std::tstring AbsolutePath;
    std::tstring FileName;
    DWORD FileSize;
    std::tstring FileEXT;
    std::tstring MD5;
    std::tstring SHA1;
    std::tstring SHA256;
    std::tstring HAS160;
    std::tstring FileHeaderDump;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("TargetID"), TargetID)
            + core::sPair(TEXT("ParentID"), ParentID)
            + core::sPair(TEXT("AbsolutePath"), AbsolutePath)
            + core::sPair(TEXT("FileName"), FileName)
            + core::sPair(TEXT("FileSize"), FileSize)
            + core::sPair(TEXT("FileEXT"), FileEXT)
            + core::sPair(TEXT("MD5"), MD5)
            + core::sPair(TEXT("SHA1"), SHA1)
            + core::sPair(TEXT("SHA256"), SHA256)
            + core::sPair(TEXT("HAS160"), HAS160)
            + core::sPair(TEXT("FileHeaderDump"), FileHeaderDump)
            ;
    }
};

// Event 구조체 정의
struct ST_FILE_FILE_EVENT : public core::IFormatterObject
{
    std::tstring EngineName;
    std::tstring EngineVersion;
    std::tstring TargetID;
    std::tstring Name;
    std::tstring AnalysisCode;
    int Severity;
    std::tstring Desc;
    std::map<std::tstring, std::tstring> DescInternational;
    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("EngineName"), EngineName)
            + core::sPair(TEXT("EngineVersion"), EngineVersion)
            + core::sPair(TEXT("TargetID"), TargetID)
            + core::sPair(TEXT("Name"), Name)
            + core::sPair(TEXT("AnalysisCode"), AnalysisCode)
            + core::sPair(TEXT("Severity"), Severity)
            + core::sPair(TEXT("Desc"), Desc)
            + core::sPair(TEXT("DescInternational"), DescInternational)
            ;
    }
};

// Detection 구조체 정의
struct ST_FILE_FILE_DETACTION : public core::IFormatterObject
{
    std::vector<ST_FILE_FILE_EVENT> FileTarget;
    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("Event"), FileTarget)
            ;
    }
};

// 최종 보고서 구조체 정의
struct ST_ANALYSIS_REPORT : public core::IFormatterObject
{
    ST_FILE_SUMMARY FileSummary;
    std::map<std::tstring, ST_FILE_FILE_TARGET> FileTargetComponent;
    ST_FILE_FILE_DETACTION Detection;
    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("Summary"), FileSummary)
            + core::sPair(TEXT("FileTarget"), FileTargetComponent)
            + core::sPair(TEXT("Detection"), Detection)
            ;
    }
};

// ST_BUILD_FILE_INFO 정의
struct ST_USER : public core::IFormatterObject
{
    int nGeneration;
    std::tstring strName;
    std::tstring strEMail;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("Generation"), nGeneration)
            + core::sPair(TEXT("Name"), strName)
            + core::sPair(TEXT("EMail"), strEMail)
            ;
    }
};

struct ST_HW_DESC : public core::IFormatterObject
{
    std::tstring strFilePath;
    std::tstring strDesc_TrialAndError;
    std::tstring strDesc_Impression;
    std::tstring strDesc_Suggestions;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("FilePath"), strFilePath)
            + core::sPair(TEXT("Desc_TrialAndError"), strDesc_TrialAndError)
            + core::sPair(TEXT("Desc_Impression"), strDesc_Impression)
            + core::sPair(TEXT("Desc_Suggestions"), strDesc_Suggestions)
            ;
    }
};

struct ST_FILE_DESC : public core::IFormatterObject
{
    std::tstring strFilePath;
    DWORD dwFileSize;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("FilePath"), strFilePath)
            + core::sPair(TEXT("dwFileSize"), dwFileSize)
            ;
    }
};

struct ST_REPORT : public core::IFormatterObject
{
    ST_USER User;
    ST_HW_DESC HWDesc;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("User"), User)
            + core::sPair(TEXT("HWDesc"), HWDesc)
            ;
    }
};

struct ST_BUILD_FILE_INFO : public ST_REPORT
{
    std::vector<ST_FILE_DESC> LibFiles;

    void OnSync(core::IFormatter& formatter)
    {
        ST_REPORT::OnSync(formatter);
        formatter
            + core::sPair(TEXT("LibFiles"), LibFiles)
            ;
    }
};
