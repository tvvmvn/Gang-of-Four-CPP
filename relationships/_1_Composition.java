package oop.relationships;

/*
In the UML, aggregation and composition are defined as 
special forms of associations with the intended meaning 
of classifying part-whole-relationships.
*/

// Exclusive (non-shareable) parts.
class AvanteEngine {};

class Avante {
  public AvanteEngine engine;
}

class _1_Composition {
  public static void main(String[] args) {
    
    AvanteEngine avanteEngine = new AvanteEngine();

    Avante avante = new Avante();
    
    avante.engine = avanteEngine;
  }
}