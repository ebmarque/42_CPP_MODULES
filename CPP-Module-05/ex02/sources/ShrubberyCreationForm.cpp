/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:59 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 19:11:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
	log(GREEN, this->getName() + " Created.");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) \
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute()), _target(other._target) 
{
	log(GREEN, this->getName() + " Created by default copy constructor");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
	if (this != &other) 
		this->_target = other._target;
		
	log(GREEN, this->getName() + " Created by copy assignment operator");
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	log(RED, this->getName() + " Destroyed.");
}

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  log(CYAN, this->getName() + ": Execute method called.");
  if (!this->getSigned())
    throw AForm::FormNotSignedException();
  else if (executor.getGrade() > this->getGradeExecute())
    throw AForm::GradeTooLowException();
  
  std::ofstream form((this->_target + "_Shrubbery").c_str());

  form << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
  form << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
  form << "            {/{/\\}{/{/\\}(_)}{/{/\\}  _" << std::endl;
  form << "         {\\{/\\(/\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
  form << "        {/{/(_)/}{\\{/\\)}{\\(_){/}/}/}/}" << std::endl;
  form << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
  form << "      {/{/{\\{\\{(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
  form << "      _{\\{/{\\{(/}{/{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
  form << "     {/{/{\\{\\(/}{/{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
  form << "      {/{/{\\{\\(/}{/{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
  form << "      _{\\{/{\\{(/}{/{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
  form << "     {/{/{\\{\\(/}{/{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
  form << "       {/{/(_)/}{\\{/\\)}{\\(_){/}/}/}/}" << std::endl;
  form << "        {\\{/\\(/\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
  form << "         {/{/\\}{/{/\\}(_)}{/{/\\}  _" << std::endl;
  form << "            {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
  form << "             _{\\ _{\\{\\/}/}/}__" << std::endl;
  form << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
  form << "              (_)  \\.-'.-/" << std::endl;
  form << "          __...--- |'-.-'| --...__" << std::endl;
  form << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
  form << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
  form << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
  form << "          ' ..     |'-_.-|" << std::endl;
  form << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
  form << "              .'   |'- .-|   '." << std::endl;
  form << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
  form << "   .-' '        '-._______.-'     '  ." << std::endl;
  form << "        .      ~," << std::endl;
  form << "    .       .   |\\   .    ' '-." << std::endl;
  form << "    ___________/  \\____________" << std::endl;
  form << "   /  Why is it, when you want \\" << std::endl;
  form << "  |  something, it is so damn   |" << std::endl;
  form << "  |    much work to get it?     |" << std::endl;
  form << "   \\___________________________/" << std::endl;

  form.close();
  
}

