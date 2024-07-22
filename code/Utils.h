#ifndef UTILS_H
#define UTILS_H

///Funciones Generales para convertir a string

/// Para convertir un c-string, o una constante, a wxString
inline wxString c_to_wx(const char *c_str) { return wxString::From8BitData(c_str); }

/// Para convertir un std::string a wxString
inline wxString std_to_wx(const std::string &std_str) { return wxString::From8BitData(std_str.c_str()); }

/// Para convertir wxString a std::string
inline std::string wx_to_std(const wxString &wx_str) { return static_cast<const char*>(wx_str.To8BitData()); }

#endif
