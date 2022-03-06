/*
** EPITECH PROJECT, 2022
** Error
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string const &message, std::string const &component)
{
    _message = message;
    _component = component;
}

std::string const &Error::getComponent() const
{
    return _component;
}

char const *Error::what() const noexcept
{
    return _message.c_str();
}

LinkError::LinkError(std::string const &message, std::string const &component)
: Error(message, component)
{

}

CommandError::CommandError(std::string const &message, std::string const &component)
: Error(message, component)
{

}

FileWrongError::FileWrongError(std::string const &message, std::string const &component)
: Error(message, component)
{

}

ValueReceiveError::ValueReceiveError(std::string const &message, std::string const &component)
: Error(message, component)
{
}


ComponentError::ComponentError(std::string const &message, std::string const &component)
: Error(message, component)
{
}

ParsingValueError::ParsingValueError(std::string const &message, std::string const &component)
: Error(message, component)
{
}

InputValueError::InputValueError(std::string const &message, std::string const &component)
: Error(message, component)
{
}

OutputValueError::OutputValueError(std::string const &message, std::string const &component)
: Error(message, component)
{
}

PinValueError::PinValueError(std::string const &message, std::string const &component)
: Error(message, component)
{
}
