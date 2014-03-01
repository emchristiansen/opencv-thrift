module OpenCVThrift.OpenCV.Features2D.Features2D where
  
import Thrift.Protocol
import Thrift.Transport
import Data.Vector
import Data.Text.Lazy

import Mat_Types

import OpenCVThrift.OpenCV.Core
import OpenCVThrift.OpenCV.Features2D

import qualified Features2D_Client

{-class -}
  {-( Thrift.Protocol.Protocol p-}
  {-, Thrift.Transport.Transport t-}
  {-) => IsClient c p t | c -> p t where-}
    {-cast :: c -> (p t, p t)-}

{-data Client p t = Client p t-}

{-instance -}
  {-( Thrift.Protocol.Protocol p-}
  {-, Thrift.Transport.Transport t-}
  {-) => IsClient (Client p t) p t where-}
  {-cast (Client protocol transport) = -}
    {-(protocol transport, protocol transport)-}

data Client p t = (Protocol p, Transport t) => Client (p t, p t)

class ToClient a p t | a -> p t where
  toClient :: a -> Client p t

instance ToClient (Client p t) p t where
  toClient = id  

detect :: ToClient a p t => a -> Text -> Mat_Types.Mat -> IO (Vector KeyPoint) 
detect client = detect' $ toClient client 
detect' (Client value) = Features2D_Client.detect value

{-detect :: IsClient c p t => c -> Text -> Mat_Types.Mat -> IO (Vector KeyPoint) -}
{-detect client = Features2D_Client.detect $ cast client-}
