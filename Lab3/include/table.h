#ifndef _TABLE_H_
#define _TABLE_H_
    /// \brief Structure for contain information about user table
    struct Table
    {
        int ** data;
        int width = 0;
        int height = 0;
        bool isEmpty = true; ///< indicates whether the table has been read from the file (in this case is the table empty)
    };
#endif 