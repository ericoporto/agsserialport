#include <string>
#include <sstream>
#include "agsp_globalvars.h"
#include "AgspSaneCheck.h"

int check(enum sp_return result, IAGSEngine *lpEngine)
{
    // exits game on error
    char *error_message;
    std::ostringstream stringStream;

    switch (result) {
        case SP_ERR_ARG:
            lpEngine->AbortGame("Error: Invalid argument.\n");
            break;
        case SP_ERR_FAIL:
            error_message = sp_last_error_message();
            stringStream << "Error: Failed: " << error_message << "\n";
            sp_free_error_message(error_message);
            lpEngine->AbortGame(stringStream.str().c_str());
            break;
        case SP_ERR_SUPP:
            lpEngine->AbortGame("Error: Not supported.\n");
            break;
        case SP_ERR_MEM:
            lpEngine->AbortGame("Error: Couldn't allocate memory.\n");
            break;
        case SP_OK:
        default:
            return result;
    }
    return result;
}

void do_check(enum sp_return result)
{
    check(result, engine);
}