/**
 * @class Cell
 * @file cell.h
 * @author your name (you@domain.com)
 * @brief Multiplie types cell class 
 * @date 2020-06-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _CELL_H_
#define _CELL_H_
    #include <iostream>
    
    /**
     * @brief Supported coordinate systems for cell data types 
     *
     */
    typedef enum{ 
        /** Info about integer value*/
        v_int,
        /** Info about string value*/ 
        v_string, 
        /** Set up as default when cell is empty*/
        empty
    } Type;

    class Cell{
        public:
            Type type = empty; ///< data type (set empty as default)
            
            int number; ///< integer value
            std::string line; ///< string value
    };
#endif // _CELL_H_