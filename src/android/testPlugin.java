//import com.pdac.myact.startact;
//import com.magicsoftware.unipaas.Events;

import android.os.Bundle;
import android.view.WindowManager;
import android.widget.TextView;

import com.imagpay.MessageHandler;
import com.imagpay.SwipeEvent;
import com.imagpay.SwipeHandler;
import com.imagpay.SwipeListener;
import com.imagpay.utils.DeviceUtils;
import android.util.Log;

import org.apache.cordova.CordovaWebView;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaInterface;
//import android.util.Log;
import android.widget.Toast;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class testPlugin extends CordovaPlugin  {
	public static final String TAG = "Cool Plugin";
	private SwipeHandler _handler;
	/**
	* Constructor.
	*/
	public testPlugin() {
		
	}
	
	
	public void initialize(CordovaInterface cordova, CordovaWebView webView) {
		super.initialize(cordova, webView);
		Log.v(TAG,"Init testPlugin");
	}
	
	public boolean execute(final String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
		final int duration = Toast.LENGTH_SHORT;
		// Shows a toast
		Log.v(TAG,"testPlugin received:"+ action);
		cordova.getActivity().runOnUiThread(new Runnable() {
			public void run() {
				Toast toast = Toast.makeText(cordova.getActivity().getApplicationContext(), action, Toast.LENGTH_SHORT);
				toast.show();
				
				_handler = new SwipeHandler(cordova.getActivity().getApplicationContext());
				_handler.setReadonly(true);
				_handler.addSwipeListener(new SwipeListener() {
					@Override
					public void onReadData(SwipeEvent event) {
						Log.d("myApp", "onreaddata") ;
						Toast toast2 = Toast.makeText(cordova.getActivity().getApplicationContext(), "readData", Toast.LENGTH_SHORT);
						toast2.show();
					}

					@Override
					public void onParseData(SwipeEvent event) {
						Toast toast3 = Toast.makeText(cordova.getActivity().getApplicationContext(), "parseData", Toast.LENGTH_SHORT);
						toast3.show();
						Log.d("myApp", "onparsedata1") ;
						// hex string message
						String[] tmps = event.getValue().split(" ");
						StringBuffer sbf = new StringBuffer();
						for (String str : tmps) {
							sbf.append((char) Integer.parseInt(str, 16));
						}

						Log.d("myApp", "onparsedata2");
						try {
							//Events.OnBrowserExternalEvent(null, sbf.toString());
						} catch (Exception e) {
							e.printStackTrace();
						}
					}

					@Override
					public void onDisconnected(SwipeEvent event) {
						Toast toast4 = Toast.makeText(cordova.getActivity().getApplicationContext(), "device is disconnected", Toast.LENGTH_SHORT);
						toast4.show();
						Log.d("myApp", "onDisconnected") ;
						try {
							//Events.OnBrowserExternalEvent(null, "on disconnect");
						} catch (Exception e) {
							e.printStackTrace();
						}
					}

					@Override
					public void onConnected(SwipeEvent event) {
						Toast toast5 = Toast.makeText(cordova.getActivity().getApplicationContext(), "device is connected", Toast.LENGTH_SHORT);
						toast5.show();
						Log.d("myApp", "onConnected") ;
						checkDevice();
					}

					@Override
					public void onStarted(SwipeEvent event) {
						Toast toast6 = Toast.makeText(cordova.getActivity().getApplicationContext(), "device has started", Toast.LENGTH_SHORT);
						toast6.show();
						Log.d("myApp", "onStarted") ;
					}

					@Override
					public void onStopped(SwipeEvent event) {
						Log.d("myApp", "onStopped") ;
					}
				});
			}
		});
		return true;
	}
	
	// @Override
	// public int getExecutionPropertiesResource() {
		//return R.raw.execution;
	// }

	// private SwipeHandler _handler;

	// @Override
	// public void onCreate(Bundle savedInstanceState) {
		// Log.d("myApp", "onCreate") ;
		//super.onCreate(savedInstanceState);
	// }

	private void checkDevice1() {
		new Thread(new Runnable() {
			@Override
			public void run()
			{
			Log.d("myApp", "onCheckDevice") ;
				_handler.powerOn();
				if (!_handler.isConnected()) {
					return;
				}
				if (_handler.isPowerOn())
					return;
				_handler.powerOn();
			}
		}).start();
	}

	private void checkDevice() {
	            new Thread(new Runnable() {
	                  @Override
	                  public void run() {
	                        if (!_handler.isConnected()) {
	                              _handler.writeCipherCode("02 08 02");
	                              return;
	                        }
	                        if (_handler.isPowerOn())
	                        {
	                              _handler.writeCipherCode("02 08 02");
	                              return;
	                        }
	                        if (_handler.isReadable())
	                        {
	                              _handler.powerOn();
	                              _handler.writeCipherCode("02 08 02");
	                        } else {
	                              if (_handler.test() && _handler.isReadable()) {
	                                    _handler.powerOn();
	                                    _handler.writeCipherCode("02 08 02");
	                              } else {

	                              }
	                        }
	                  }
	            }).start();
	      }


	public void onDestroy() {
		_handler.onDestroy();
		super.onDestroy();
	}

}