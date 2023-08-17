﻿#include <CefViewBrowserClient.h>

#pragma region std_headers
#include <sstream>
#include <string>
#include <algorithm>
#pragma endregion std_headers

#pragma region cef_headers
#include <include/cef_app.h>
#pragma endregion cef_headers

#include <Common/CefViewCoreLog.h>

CefRefPtr<CefDialogHandler>
CefViewBrowserClient::GetDialogHandler()
{
  return this;
}

#if CEF_VERSION_MAJOR > 91
bool
CefViewBrowserClient::OnFileDialog(CefRefPtr<CefBrowser> browser,
                                   FileDialogMode mode,
                                   const CefString& title,
                                   const CefString& default_file_path,
                                   const std::vector<CefString>& accept_filters,
                                   CefRefPtr<CefFileDialogCallback> callback)
#else
bool
CefViewBrowserClient::OnFileDialog(CefRefPtr<CefBrowser> browser,
                                   FileDialogMode mode,
                                   const CefString& title,
                                   const CefString& default_file_path,
                                   const std::vector<CefString>& accept_filters,
                                   int selected_accept_filter,
                                   CefRefPtr<CefFileDialogCallback> callback)
#endif
{
  auto delegate = client_delegate_.lock();
  if (delegate)
    return delegate->onFileDialog(browser, mode, title, default_file_path, accept_filters, callback);

  return false;
}
