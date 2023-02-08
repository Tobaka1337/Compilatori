package syntaxtree.node;

import type.Type;
import visitor.Visitor;
import syntaxtree.node.expr.Id;

import java.util.ArrayList;

public class FunDeclOp extends Node {

    private boolean isMain;
    private Id id;
    private ArrayList<ParDeclOp> parDeclOpList;
    private TypeOp typeOp;
    private BodyOp bodyOp;

    public FunDeclOp(boolean isMain, Id id, ArrayList<ParDeclOp> parDeclOpList, TypeOp typeOp, BodyOp bodyOp) {
        if(!validTypeOp(typeOp))
            throw new RuntimeException("Il TypeOp inserito non ha un tipo valido.");

        this.isMain = isMain;
        this.id = id;
        this.parDeclOpList = parDeclOpList;
        this.typeOp = typeOp;
        this.bodyOp = bodyOp;
    }

    public FunDeclOp(Id id, ArrayList<ParDeclOp> parDeclOpList, TypeOp typeOp, BodyOp bodyOp) {
        if(!validTypeOp(typeOp))
            throw new RuntimeException("Il TypeOp inserito non ha un tipo valido.");

        this.isMain = false;
        this.id = id;
        this.parDeclOpList = parDeclOpList;
        this.typeOp = typeOp;
        this.bodyOp = bodyOp;
    }

    public Id getId() {
        return id;
    }

    public void setId(Id id) {
        this.id = id;
    }

    public ArrayList<ParDeclOp> getParDeclOpList() {
        return parDeclOpList;
    }

    public void setParDeclOpList(ArrayList<ParDeclOp> parDeclOpList) {
        this.parDeclOpList = parDeclOpList;
    }

    public TypeOp getTypeOp() {
        return typeOp;
    }

    public void setTypeOp(TypeOp typeOp) {
        if(!validTypeOp(typeOp))
            throw new RuntimeException("Il TypeOp inserito non ha un tipo valido.");

        this.typeOp = typeOp;
    }

    public BodyOp getBodyOp() {
        return bodyOp;
    }

    public void setBodyOp(BodyOp bodyOp) {
        this.bodyOp = bodyOp;
    }

    public boolean isMain() {
        return isMain;
    }

    public void setMain(boolean main) {
        isMain = main;
    }

    public Object accept(Visitor visitor){
        return visitor.visit(this);
    }

    private boolean validTypeOp(TypeOp typeOp) {
        String type = typeOp.getAttribute();
        if(Type.basicTypes.contains(type)) return true;
        if(type.equals(Type.VOID)) return true;
        return false;
    }
}
