#ifndef STRING_COLOR_H
#define STRING_COLOR_H

#ifdef __linux__

#define BLACK          "\033[30m"
#define RED            "\033[31m"
#define GREEN          "\033[32m"
#define YELLOW         "\033[33m"
#define BLUE           "\033[34m"
#define MAGENTA        "\033[35m"
#define CYAN           "\033[36m"
#define WHITE          "\033[37m"
#define RESET          "\033[0m"

#define BOLD_BLACK     "\033[1;30m"
#define BOLD_RED       "\033[1;31m"
#define BOLD_GREEN     "\033[1;32m"
#define BOLD_YELLOW    "\033[1;33m"
#define BOLD_BLUE      "\033[1;34m"
#define BOLD_MAGENTA   "\033[1;35m"
#define BOLD_CYAN      "\033[1;36m"
#define BOLD_WHITE     "\033[1;37m"

#else

#define BLACK          ""
#define RED            ""
#define GREEN          ""
#define YELLOW         ""
#define BLUE           ""
#define MAGENTA        ""
#define CYAN           ""
#define WHITE          ""
#define RESET          ""

#define BOLD_BLACK     ""
#define BOLD_RED       ""
#define BOLD_GREEN     ""
#define BOLD_YELLOW    ""
#define BOLD_BLUE      ""
#define BOLD_MAGENTA   ""
#define BOLD_CYAN      ""
#define BOLD_WHITE     ""

#endif


#endif // STRING_COLOR_H
