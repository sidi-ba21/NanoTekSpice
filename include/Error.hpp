/*
** EPITECH PROJECT, 2022
** Exception
** File description:
** Exception
*/

#include <string>
#include <exception>

#ifndef ERROR_HPP_
#define ERROR_HPP_

class Error : public std::exception
{
    public:
        Error(std::string const &message, std::string const &component = "Unknown");
        virtual const std::string &getComponent() const;
        char const *what() const noexcept;
    private:
        std::string _message;
        std::string _component;
};

class LinkError : public Error
{
    public:
        LinkError(std::string const &message, std::string const &component = "Unknown");
};

class CommandError : public Error
{
    public:
        CommandError(std::string const &message, std::string const &component = "Unknown");
};

class FileWrongError : public Error
{
    public:
        FileWrongError(std::string const &message, std::string const &component = "Unknown");
};

class ValueReceiveError : public Error
{
    public:
        ValueReceiveError(std::string const &message, std::string const &component = "Unknown");
};

class ComponentError : public Error
{
    public:
        ComponentError(std::string const &message, std::string const &component = "Unknown");
};

class ParsingValueError : public Error
{
    public:
        ParsingValueError(std::string const &message, std::string const &component = "Unknown");
};

class InputValueError : public Error
{
    public:
        InputValueError(std::string const &message, std::string const &component = "Unknown");
};

class OutputValueError : public Error
{
    public:
        OutputValueError(std::string const &message, std::string const &component = "Unknown");
};

class PinValueError : public Error
{
    public:
        PinValueError(std::string const &message, std::string const &component = "Unknown");
};

#endif /* !EXCEPTION_HPP_ */
