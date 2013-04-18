package com.aldebaran;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map;

import com.aldebaran.qimessaging.GenericObject;
import com.aldebaran.qimessaging.QimessagingService;

public class ReplyService implements QimessagingService
{

  private GenericObject _obj = null;

  public String reply(String str)
  {
    System.out.println("Replying : " + str + "bim !");
    return str.concat("bim !");
  }

  public Integer answer(Integer val)
  {
    System.out.println("Replying : " + (val + 1));
    return val + 1;
  }

  public Float   answerFloat(Float val)
  {
    return val + 1;
  }

  public Boolean answerBool(Boolean val)
  {
    if (val == true)
      return false;

    return true;
  }

  public Integer add(Integer a, Integer b)
  {
    System.out.println(a + " + " + b + " = " + (a + b));
    return a + b;
  }

  public Map<Integer, Boolean> abacus(Map<Integer, Boolean> map)
  {
    Map<Integer, Boolean> ret = new Hashtable<Integer, Boolean>();

    ret.put(1, false);
    ret.put(2, true);
    for( Iterator<Integer> ii = map.keySet().iterator(); ii.hasNext();)
    {
      Integer key = (Integer) ii.next();
      Boolean value = map.get(key);

      System.out.println("valeur : ["+ key + "] = " + value);
    }

    System.out.println("Returning : " + ret);
    return ret;
  }

  public ArrayList<Integer> echoIntegerList(ArrayList<Integer> l)
  {

    for (Iterator<Integer> it = l.iterator(); it.hasNext();)
    {
      System.out.println("Value : " + it.next());
    }
    return l;
  }

  public void setObj(GenericObject obj)
  {
    _obj = obj;
  }

  public void triggerFireEvent(Integer val)
  {
    System.out.println("Fire event triggered (" + val + ")");

    _obj.emitEvent("fire", val);
  }

}
