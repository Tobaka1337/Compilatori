package syntaxtree.node.expr.binaryexpr;

import visitor.Visitor;
import syntaxtree.node.expr.Expr;

public class DiffOp extends BinaryExpr {

    public DiffOp(Expr left, Expr right) {
        super(left, right);
    }

    public Object accept(Visitor visitor){
        return visitor.visit(this);
    }
}
