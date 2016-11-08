#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "Base.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	public:
		OpCommand() : Command() {}
		OpCommand(int i) {
			root = new Op(i);
		}
};

class AddCommand : public Command {
	public:
		AddCommand() : Command() {}
		AddCommand(Command* c, int i) {
			Base* b = new Op(i);
			root = new Add(c->get_root(), b);
		}
};

class SubCommand : public Command {
	public:
		SubCommand() : Command() {}
		SubCommand(Command* c, int i) {
			Base* b = new Op(i);
			root = new Sub(c->get_root(), b);
		}
};

class MultCommand : public Command {
	public:
		MultCommand() : Command() {}
		MultCommand(Command* c, int i) {
			Base* b = new Op(i);
			root = new Mult(c->get_root(), b);
		}
};

class SqrCommand : public Command {
	public:
		SqrCommand() : Command() {}
		SqrCommand(Command* c) {
			root = new Sqr(c->get_root());
		}
};

#endif //__COMMAND_CLASS__